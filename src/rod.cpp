#include "../inc/element.h"
#include "../inc/rod.h"
#include <Eigen/Sparse>

// Constructor of the class rod
Rod::Rod(double Len, int num_elements, double Young_Modulus, double a_0, bool variable_area){
    // Allocating memory and initializing global stiffness matrix with zeros
    this->length = Len;
    this->number_of_elements = (int) num_elements;
    this->young_modulus = Young_Modulus;
    this->element_length = this->length/this->number_of_elements;
    this->number_of_nodes = this->number_of_elements + 1;
    this->a_0 = a_0;
    this->variable_area = variable_area;

    this->global_stiffness.resize(this->number_of_nodes, this->number_of_nodes);
    for(int i = 0; i < this->number_of_nodes; i++){
        for (int j = 0; j < this->number_of_nodes; j++){
            this->global_stiffness.insert(i, j) = 0;
        }
    }

    // Allocating memory and initializing elements array
    this->elements = new Element[this->number_of_elements];
    for (int i = 0; i < this->number_of_elements; i++){
        double area = this->a_0;
        if (this->variable_area){
            area = this->a_0 * (1 + ((i * this->element_length) / this->length) + 1 / (2 * this->number_of_elements));
        }
        this->elements[i] = Element(i*(this->element_length), (i+1)*(this->element_length), area, this->young_modulus, this->element_length);
    }

    // filling correct values in global stiffness matrix using local stiffness matrix of the containing elements
    for(int i = 0; i < this->number_of_elements; i++){
        this->global_stiffness.coeffRef(i, i) += this->elements[i].get_stiffness_index(0, 0);
        this->global_stiffness.coeffRef(i, i + 1) += this->elements[i].get_stiffness_index(0, 1);
        this->global_stiffness.coeffRef(i + 1, i) += this->elements[i].get_stiffness_index(1, 0);
        this->global_stiffness.coeffRef(i + 1, i + 1) += this->elements[i].get_stiffness_index(1, 1);
    }

}

// get_elements() : returns an array of elements of the rod
const Element * Rod::get_elements(){
    return this->elements;
}

// get_element(int i) : returns ith index element from "elements" array
const Element Rod::get_element(int index){
    return this->elements[index];
}

// get_stiffness() : returns gloabal stiffness matrix of the rod
const Eigen::SparseMatrix<double> Rod::get_stiffness(){
    return this->global_stiffness;
}

// destructor of Rod class: deallocated memory allocated to elements
Rod::~Rod() {
    delete[] this->elements;
}