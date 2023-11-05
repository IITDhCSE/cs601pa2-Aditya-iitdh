#include <iostream>
using namespace std;

class Element
{
private:
    float L;
    float A;
    float **K;
public:
    void setMembers(float l, float a, int E, int n)
    {
        L = l;
        A = a;
        K = new float*[n];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                K[i][j] = 0;
            }
        }
    }
};