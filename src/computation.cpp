#include <iostream>
#include <eigen3/Eigen/Dense>
using namespace std;
/*
This file contains code to compute the inverse of global stiffness matrix and 
multiply it with the force vector to get displacement vector.
*/

// Matrix multiplication
Eigen::MatrixXd matMul(Eigen::MatrixXd x, Eigen::MatrixXd y)
{
    return x * y;
}

// Inverse of matrix
Eigen::MatrixXd matInverse(Eigen::MatrixXd x)
{
    return x.inverse();
}

// Pseudo-inverse of matrix
Eigen::MatrixXd matPseudoInverse(Eigen::MatrixXd x)
{
    return x.completeOrthogonalDecomposition().pseudoInverse();
}

// Display the displacement vector
void display(Eigen::MatrixXd u)
{
    cout << "Displacement vector from x = 0 to x = L" << endl;
    cout << u << endl;
}

void compute(Eigen::MatrixXd K, Eigen::MatrixXd F)
{
    Eigen::MatrixXd inv, u;
    if(K.determinant() == 0)    // If determinant of stiffness matrix is 0 then inverse is not defined, so we have used pseudo-inverse.
    {
        cout << "Determinant of stiffness matrix is 0!" << endl;
        cout << "Computing Pseudo-Inverse instead ... " << endl;
        cout << "Pseudo-Inverse :" << endl;
        inv = matPseudoInverse(K);
        cout << inv << endl;
    }
    else
    {
        cout << "Inverse of stiffness matrix is :" << endl;
        inv = matInverse(K);
        cout << inv << endl;
    }
    
    u = matMul(inv, F);
    display(u);
}