#include <iostream>
#include <eigen3/Eigen/Dense>
using namespace std;

class Element
{
private:
    float L;
    float A;
    Eigen::MatrixXf K;
public:
    void setMembers(float l, float a, float E, int n)
    {
        L = l;
        A = a;
        K(n, n);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                K(i, j) = 0;
            }
        }
    }
};