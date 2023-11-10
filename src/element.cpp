#include "../inc/discretize.h"

// Constructor of the class Element
Element::Element(double XA, double XB, double Area){
    // initializing values of xa, xb, and area of the class element
    this->xa = XA;
    this->xb = XB;
    this->area = Area;

    // Allocating memory to stiffness matrix 
    this->stiffness(2, 2);

    // Initializing values of stiffness matrix
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            if(i == j){
                this->stiffness(i, j) = area;
            }
            else{
                this->stiffness(i, j) = -area;
            }
        }
    }

}

// get_area() : returns area of the element
double Element::get_area(){
    return this->area;
}

// get_xa() : returns starting point coordinates of the element
// double Element::get_xa(){
//     return this->xa;
// }

// get_stiffness() : returns local stiffness matrix of the element
const Eigen::MatrixXd Element::get_stiffness(){
    return this->stiffness;
}

// get_stiffness_index(int i, int j) : returns value at ith row and jth column of the local stiffness matrix of the element
double Element::get_stiffness_index(int index_i, int index_j){
    return this->stiffness(index_i, index_j);
}