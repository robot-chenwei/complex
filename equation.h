//
// Created by baymin on 2019/4/28.
//

#ifndef COMPLEX_EQUAION_H
#define COMPLEX_EQUAION_H

#include "complex.h"

const double EQUANTION_DEFAULT_ESP = 1e-6;

class equation {
private:
    complex A, B, C, D, E;
    int order;
    double Esp;
public:
    equation() : Esp(EQUANTION_DEFAULT_ESP){}
    equation(complex a, complex b) : A(a), B(b), order(1), Esp(EQUANTION_DEFAULT_ESP) {}
    equation(complex a, complex b, complex c) : A(a), B(b), C(c), order(2), Esp(EQUANTION_DEFAULT_ESP)  {}
    equation(complex a, complex b, complex c, complex d)  : A(a), B(b), C(c), D(d), order(3), Esp(EQUANTION_DEFAULT_ESP)  {}
    equation(complex a, complex b, complex c, complex d, complex e) : A(a), B(b), C(c), D(d), E(e), order(4), Esp(EQUANTION_DEFAULT_ESP)  {}
    int solve(complex ans[]);
};

#endif