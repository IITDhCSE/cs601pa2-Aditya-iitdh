#include "element.h"
#include <Eigen/Sparse>
/*
This class contains necessary attributes and functions to define a 1D rod Fininte Element Analysis.
Parameters:
    elements : it is an array of elements of the rod
    global_stiffness : it is a 2D matrix of global stiffness matrix

Functions:
    get_elements() : returns an array of elements of the rod
    get_element(int i) : returns ith index element from "elements" array
    get_stiffness() : returns gloabal stiffness matrix of the rod
    ~Rod() : Destructor of class Rod
*/
#ifndef _Rod_h_
#define _Rod_h_
class Rod {
    private:
        double length;
        double young_modulus;
        double element_length;
        int number_of_elements;
        int number_of_nodes;
        double a_0;
        bool variable_area;
        Element * elements;
        Eigen::SparseMatrix<double> global_stiffness;
    public:
    Rod(double Len, int num_elements, double Young_Modulus, double a_0, bool variable_area);
    const Element * get_elements();
    const Element get_element(int index);
    const Eigen::SparseMatrix<double> get_stiffness();
    ~Rod();
};
#endif