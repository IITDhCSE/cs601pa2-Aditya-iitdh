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
    float *K;
    float *F;
    float *u;
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
        K = new float[dim * dim];
        F = new float[dim];
        u = new float[dim];
    }
};