#include <iostream>
#include <eigen3/Eigen/Dense>
using namespace std;

// Matrix multiplication
Eigen::MatrixXf matMul(Eigen::MatrixXf x, Eigen::MatrixXf y)
{
    return x * y;
}

// Inverse of matrix
Eigen::MatrixXf matInverse(Eigen::MatrixXf x)
{
    return x.inverse();
}

// Pseudo-inverse of matrix
Eigen::MatrixXf matPseudoInverse(Eigen::MatrixXf x)
{
    return x.completeOrthogonalDecomposition().pseudoInverse();
}

// Display the displacement vector
void display(Eigen::MatrixXf u)
{
    cout << "Displacement vector from x = 0 to x = L" << endl;
    cout << u << endl;
}

void compute(Eigen::MatrixXf K, Eigen::MatrixXf F)
{
    Eigen::MatrixXf inv, u;
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