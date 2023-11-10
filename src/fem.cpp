#include "../inc/discretize.h"
#include "computation.cpp"

/*
This file contains code to discretize and solve a 1D rod problem assigned in CS 601 assignment 2 using finite element analysis.
*/
void solve(Rod &rod, Eigen::MatrixXd force){
    //Solve the model and get displacements
    compute(rod.get_stiffness(), force);
}

int main(){
    // Declaring a rod object
    Rod rod = Rod();
    // Declaring and allocating memory to force vector
    Eigen::MatrixXd force(NUMBER_OF_NODES, 1);
    
    // Initializing force vector
    for (int i = 0; i < NUMBER_OF_NODES; i++){
        if (i == 0)
        {
            force(i,0) = FORCE;
        }
        else if (i == NUMBER_OF_NODES - 1)
        {
            force(i,0) = -FORCE;
        }
        else
        {
            force(i,0) = 0;
        }
    }

    // Solving the Ku = F equation
    solve(rod, force);
}
