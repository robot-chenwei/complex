//
// Created by baymin on 2019/4/28.
//

#include "equation.h"

int equation::roots(complex ans[]) {
    if (A.norm() <Esp) {
        return 0;
    } else if (1 == order) { // y = ax+b
        ans[0] = 0.0 - B / A;
        return 1;
    } else if (2 == order) { // y = ax^2+bx+c
        complex det[2];
        sqrt(B * B - 4.0 * A * C, det);
        ans[0] = -0.5 * (B + det[0]) / A;
        ans[0] = -0.5 * (B + det[1]) / A;
        return 2;
    } else if (3 == order) { // y = ax^3+bx^2+cx+d
        complex AA = B / A / -3.0;
        complex BB1 = B * C / A / A / 6.0 - B * B * B / A / A / A / 27.0 - D / A / 2.0;
        complex BB21 = BB1;
        complex BB22 = C / A / 3.0 - B * B / A / A / 9.0;
        complex BB2 = power(BB21 * BB21 + BB22 * BB22 * BB22, 0.5);
        complex BB = power(BB1 + BB2, 1.0/3.0);
        complex CC = power(BB1 - BB2, 1.0/3.0);
        ans[0] = AA + BB + CC;
        ans[1] = AA + BB * complex(-0.5, +0.5 * sqrt(3.0)) + CC * complex(-0.5, -0.5 * sqrt(3.0));
        ans[2] = AA + BB * complex(-0.5, -0.5 * sqrt(3.0)) + CC * complex(-0.5, +0.5 * sqrt(3.0));
        return 3;
    } else if (4 == order) {
        complex al = -3.0 * B * B / (8.0 * A * A) + C / A;
        complex be = B * B * B / (8.0 * A * A * A) - B * C / (2.0 * A * A) + D  / A;
        complex ga = -3.0 * B * B * B * B / (256.0 * A * A * A * A) + B * B * C / (16.0 * A * A * A)  - B * D / (4.0 * A * A) + E / A;
        if (norm(be) < 1e-6) { // be = 0 : u^4 + al * u^2 + ga = 0;
            complex XX[4], YY[2];
            sqrt(al * al - 4.0 * ga, YY);
            sqrt(-0.5*(al + YY[0]), XX + 0);
            sqrt(-0.5*(al - YY[0]), XX + 2);
            for (int i = 0; i < 4; ++ i) {
                ans[i] = XX[i] - 0.25 * B / A;
            }
            return 4;
        }
        complex P = al * al / -12.0 - ga;
        complex Q = al * al * al / -108.0 + al * ga / 3.0 - be * be / 8.0;
        complex R = power(Q * Q / 4.0 + P * P * P / 27.0, 0.5);
        complex U = power(0.5 * Q + R, 1.0/3);
        complex y = -5.0 / 6.0 * al - U;
        if (U.norm() > 1e-5) {
            y = y + P / 3.0 / U;
        }
        complex S[2], T[4];
        sqrt(al + 2.0 * y, S);
        sqrt(-3.0 * al - 2.0 * y - 2.0 * be / S[0], T+0);
        sqrt(-3.0 * al - 2.0 * y - 2.0 * be / S[1], T+2);
        ans[0] = -0.25 * B / A + 0.5 * (S[0] + T[0]);
        ans[1] = -0.25 * B / A + 0.5 * (S[0] - T[0]);
        ans[2] = -0.25 * B / A + 0.5 * (S[1] + T[2]);
        ans[3] = -0.25 * B / A + 0.5 * (S[1] - T[2]);
        return 4;
    }
    return 0;
}
