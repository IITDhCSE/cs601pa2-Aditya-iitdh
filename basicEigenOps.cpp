/*
This file illustrates the use of some operations on Matrices using Eigen package.
These operations can turn out to be useful in the assignment.
*/
#include <iostream>
#include <eigen3/Eigen/Dense>
using namespace std;


int main()
{
    int N = 2;

    cout << "Matrix m1:" << endl;
    Eigen::MatrixXf m1(N, N);
    m1(0,0) = 0.1;
    m1(0,1) = 11.3;
    m1(1,0) = 22.1;
    m1(1,1) = 36.3;
    cout << m1 << endl;

    cout << endl;
    
    cout << "Matrix m2:" << endl;
    Eigen::MatrixXf m2(N, 1);
    m2(0,0) = 0.111;
    m2(1,0) = 1.134;
    cout << m2 << endl;

    cout << endl;

    // Matrix-vector multiplication
    cout << "m1 * m2 :" << endl;
    Eigen::MatrixXf m3 = m1 * m2;
    cout << m3 << endl;

    cout << endl;

    cout << "Inverse of m1" << endl;
    cout << m1.inverse() << endl;

    cout << endl;

    // We are computing pseudo-inverse in case the determinant of stiffness is coming as 0. 
    cout << "Pseudo-Inverse of matrix m1:" << endl;
    cout << m1.completeOrthogonalDecomposition().pseudoInverse() << endl;

    
    return 0;
}