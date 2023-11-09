#include "computation.cpp"
#include <eigen3/Eigen/Dense>
using namespace std;

int main()
{
    int N = 2;
    int PROB = 1;
    Eigen::MatrixXf K(2, 2);
    Eigen::MatrixXf F(2, 1);

    // K << 1, 2, 3, 4;
    K << 1, -1, -1, 1;
    F << 1, -1;

    cout << "K :" << endl;
    cout << K << endl;
    cout << endl;

    cout << "F :" << endl;
    cout << F << endl;
    cout << endl;

    compute(K, F);

    return 0;
}