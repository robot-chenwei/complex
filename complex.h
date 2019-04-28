//
// Created by baymin on 2019/4/28.
//

#ifndef COMPLEX_COMPLEX_H
#define COMPLEX_COMPLEX_H

#include <cmath>
#include <iostream>

const double DEFAULT_COMPLEX_ESP = 1e-6;

class complex
{
public:
    double Esp;
    double Re, Im;

    complex() : Re(0), Im(0), Esp(DEFAULT_COMPLEX_ESP) {}
    complex(double re, double im = 0, double esp = DEFAULT_COMPLEX_ESP) : Re(re), Im(im), Esp(esp) {}
    complex(const complex& c) { Re = c.Re; Im = c.Im; Esp = c.Esp;}

    double norm() { return sqrt(Re * Re + Im * Im); }
    double arc() { return atan2(Im, Re); }

    friend double norm(complex c);
    friend std::ostream& operator << (std::ostream &out, complex &a);
    friend complex operator + (complex a, complex b);
    friend complex operator - (complex a, complex b);
    friend complex operator * (complex a, complex b);
    friend complex operator / (complex a, complex b);
    friend complex power (complex a, double n);         // only return one answer
    friend void sqrt (complex a, complex ans[]);          // return two answers
    friend void curt (complex a, complex ans[]);          // return three answers
};

#endif //COMPLEX_COMPLEX_H
