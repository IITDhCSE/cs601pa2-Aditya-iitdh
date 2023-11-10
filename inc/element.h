#include <eigen3/Eigen/Dense>
/*
This class contains necessary attributes and fuctions to define a 1D rod element in Finite Element Analysis.
Parameters :
    xa : Coordinates of starting point of the element
    xb : Coordinates of ending point of the element
    Area : Area of the element
    stiffness : Local stiffness matrix of the element

Functions :
    get_area() : returns area of the element
    get_xa() : returns starting point coordinates of the element
    get_stiffness() : returns local stiffness matrix of the element
    get_stiffness_index(int i, int j) : returns value at ith row and jth column of the local stiffness matrix of the element
*/
class Element {
    private:
        double xa;
        double xb;
        double area;
        Eigen::MatrixXd stiffness;
    public:
    Element(){};
    Element(double, double, double);
    double get_area();
    // double get_xa();
    // double ** get_stiffness();
    const Eigen::MatrixXd get_stiffness();
    double get_stiffness_index(int, int);
};