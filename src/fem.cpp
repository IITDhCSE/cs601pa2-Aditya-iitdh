#include "../inc/discretize.h"

/*
This file contains code to discretize and solve a 1D rod problem assigned in CS 601 assignment 2 using finite element analysis.
*/
double * solve(Rod rod, double * force){
    //Solve the model and get displacements
}

int main(){
    // Declaring a rod object
    Rod rod = Rod();
    // Declaring and allocating memory to force vector
    double * force = new double[NUMBER_OF_NODES];
    
    // Initializing force vector
    for (int i = 0; i < NUMBER_OF_NODES; i++){
        if (i == 0)
        {
            force[i] = FORCE;
        }
        else if (i == NUMBER_OF_NODES - 1)
        {
            force[i] = -FORCE;
        }
        else
        {
            force[i] = 0;
        }
    }
}
