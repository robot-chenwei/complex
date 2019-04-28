//
// Created by baymin on 2019/4/28.
//

#include "complex.h"

double norm(complex c)
{
    return c.norm();
}

std::ostream& operator << (std::ostream &out, complex &c)
{
    if (fabs(c.Re) < c.Esp)
        out << "0";
    else
        out << c.Re;
    if (c.Im > c.Esp)
        out << " + " << c.Im << " i";
    else if (c.Im < -c.Esp)
        out << " - " << -c.Im << " i";
    return out;
}

complex operator + (complex a, complex b)
{
    return complex(a.Re + b.Re, a.Im + b.Im);
}

complex operator - (complex a, complex b)
{
    return complex(a.Re - b.Re, a.Im - b.Im);
}

complex operator * (complex a, complex b)
{
    return complex(a.Re * b.Re - a.Im * b.Im, a.Re * b.Im + a.Im * b.Re);
}

complex operator / (complex a, complex b)
{
    double denominator = b.Re * b.Re + b.Im * b.Im;
    return complex((a.Re * b.Re + a.Im * b.Im) / denominator, (a.Im * b.Re - a.Re * b.Im) / denominator);
}

complex power (complex c, double n)
{
    if (fabs(n) < c.Esp) {
        return complex(1.0, 0.0);
    }
    double norm = pow(c.norm(), n);
    double angle = c.arc() * n;
    return complex(norm * cos(angle), norm * sin(angle));
}

void sqrt (complex c, complex ans[])
{
    double norm = sqrt(c.norm());
    double angle1 = c.arc() / 2.0;
    double angle2 = angle1 + acos(-1.0);
    ans[0] = complex(norm * cos(angle1), norm * sin(angle1));
    ans[1] = complex(norm * cos(angle2), norm * sin(angle2));
}

void curt (complex c, complex ans[])
{
    double norm = pow(c.norm(), 1.0/3);
    double angle1 = c.arc() / 3;
    double angle2 = angle1 + acos(-1.0) * 2.0 / 3.0;
    double angle3 = angle1 + acos(-1.0) * 4.0 / 3.0;
    ans[0] = complex(norm * cos(angle1), norm * sin(angle1));
    ans[1] = complex(norm * cos(angle2), norm * sin(angle2));
    ans[2] = complex(norm * cos(angle3), norm * sin(angle3));
}
