#include "element.h"
/*
This class contains necessary attributes and functions to define a 1D rod Fininte Element Analysis.
Parameters:
    elements : it is an array of elements of the rod
    global_stiffness : it is a 2D matrix of global stiffness matrix

Functions:
    get_elements() : returns an array of elements of the rod
    get_element(int i) : returns ith index element from "elements" array
    get_stiffness() : returns gloabal stiffness matrix of the rod
*/
#ifndef _Rod_h_
#define _Rod_h_
class Rod {
    private:
        Element * elements;
        Eigen::MatrixXd global_stiffness;
    public:
    Rod();
    const Element * get_elements();
    const Element get_element(int);
    const Eigen::MatrixXd get_stiffness();
};
#endif