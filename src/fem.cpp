/*
This file contains code to discretize and solve a 1D rod problem assigned in CS 601 assignment 2 using finite element analysis.
*/
#include "../inc/rod.h"
#include <Eigen/Sparse>
#include <iostream>
#include <chrono>

#ifndef NUMBER_OF_ELEMENTS
#define NUMBER_OF_ELEMENTS 2
#endif

#ifndef PROB
#define PROB 1
#endif

#ifndef VARIABLE_AREA
#if PROB == 1
#define VARIABLE_AREA false
#else
#define VARIABLE_AREA true
#endif
#endif

#ifndef LENGTH
#define LENGTH 0.5
#endif

#ifndef FORCE
#define FORCE 5000
#endif

#ifndef A_0
#define A_0 12.5e-4
#endif

#ifndef YOUNG_MODULUS
#define YOUNG_MODULUS 7e10
#endif

int main(){
    auto start_time = std::chrono::high_resolution_clock::now();
    // Declaring a rod object
    std::cout<<"\nHello!\n"<<std::endl;
    Rod rod = Rod(LENGTH, NUMBER_OF_ELEMENTS, YOUNG_MODULUS, A_0, VARIABLE_AREA);
    int number_of_nodes = NUMBER_OF_ELEMENTS + 1;
    // Declaring and allocating memory to force vector
    Eigen::VectorXd force(number_of_nodes);
    
    // Initializing force vector
    for (int i = 0; i < number_of_nodes; i++) {
        if (i == 0) {
            force(i) = FORCE;
        } else if (i == number_of_nodes - 1) {
            force(i) = -FORCE;
        } else {
            force(i) = 0;
        }
    }
    
    // Declaring a solver
    Eigen::SparseQR<Eigen::SparseMatrix<double>, Eigen::COLAMDOrdering<int>> solver;
    double shiftValue = 1e-3;
    int count = 0;
    bool decomposed = false;
    // iterating till matrix gets decomposed or upto max 10 times
    while((count<10) && !(decomposed)){
        // Solve the shifted linear system (A - shift * I) * x = b using SparseQR
        solver.compute(rod.get_stiffness() - shiftValue * Eigen::SparseMatrix<double>(rod.get_stiffness()));
        if (solver.info() == Eigen::Success) {
            decomposed = true;
        }
        // shifting the shift value if matrix does not get decomposed
        shiftValue *= 2;
        count++;
    }

    if(!decomposed){
        std::cout<<"Matrix could not be decomposed!"<<std::endl;
        return 1;
    }

    Eigen::VectorXd x = solver.solve(force);

    auto end_time = std::chrono::high_resolution_clock::now();
    std::cout << "Computed Displacement vector x:" << std::endl << x << std::endl;
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;

    return 0;
}