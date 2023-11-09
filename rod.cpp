#include <iostream>
#include "element.cpp"
using namespace std;

class Rod
{
private:
    float L;
    float A0;
    int P;
    float E;
    int N;
    int PROB;
    Element *e;
    Eigen::MatrixXf K;
    Eigen::MatrixXf F;
    Eigen::MatrixXf u;
    int dim;
public:
    Rod(int n, int prob)    // constructor to initialize rod properties, number of elements and problem type
    {
        L = 0.5;
        A0 = 12.5e-4;
        P = 5000;
        E = 70.0e+9;
        N = n;
        PROB = prob;
        int dim = (2 * N) - 1;
        e = new Element[N];
        K(n, n);
        F(n, 1);
        u(n, 1);
    }
};