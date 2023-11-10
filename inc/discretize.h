/*
This file contains required header files for fem.cpp along with macros used in all the other files.
*/

#ifndef DIM
#define DIM 1
#endif

#ifndef NUMBER_OF_ELEMENTS
#define NUMBER_OF_ELEMENTS 2
#endif

#ifndef PROB
#define PROB 1
#endif

#ifndef LENGTH
#define LENGTH 0.5
#endif

#ifndef FORCE
#define FORCE 5000
#endif

#ifndef A_0
#define A_0 12.5e-4
#endif

#ifndef YOUNG_MODULUS
#define YOUNG_MODULUS 7e10
#endif

#ifndef NUMBER_OF_NODES
#define NUMBER_OF_NODES NUMBER_OF_ELEMENTS+1
#endif

#ifndef ELEMENT_LENGTH
#define ELEMENT_LENGTH LENGTH/NUMBER_OF_ELEMENTS
#endif