#include "../inc/discretize.h"

// Constructor of the class rod
Rod::Rod(){
    // Allocating memory and initializing global stiffness matrix with zeros
    this->global_stiffness(NUMBER_OF_NODES, NUMBER_OF_NODES);
    for(int i = 0; i < NUMBER_OF_NODES; i++){
        for (int j = 0; j < NUMBER_OF_NODES; j++){
            this->global_stiffness(i, j) = 0;
        }
    }

    // Allocating memory and initializing elements array
    this->elements = new Element[NUMBER_OF_ELEMENTS];
    for (int i = 0; i < NUMBER_OF_ELEMENTS; i++){
        double area = A_0;
        if (PROB == 2){
            area = A_0 * (1 + ((i * ELEMENT_LENGTH) / LENGTH) + 1 / (2 * NUMBER_OF_ELEMENTS));
        }
        this->elements[i] = Element(i*(ELEMENT_LENGTH), (i+1)*(ELEMENT_LENGTH), area);
    }

    // filling correct values in global stiffness matrix using local stiffness matrix of the containing elements
    for(int i = 0; i < NUMBER_OF_ELEMENTS; i++){
        this->global_stiffness(i, i) += this->elements[i].get_stiffness_index(0, 0);
        this->global_stiffness(i, i + 1) += this->elements[i].get_stiffness_index(0, 1);
        this->global_stiffness(i + 1, i) += this->elements[i].get_stiffness_index(1, 0);
        this->global_stiffness(i + 1, i + 1) += this->elements[i].get_stiffness_index(1, 1);
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
const Eigen::MatrixXd Rod::get_stiffness(){
    return this->global_stiffness;
}