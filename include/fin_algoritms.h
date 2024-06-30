// file: fin_algorithms.h


#ifndef _FIN_ALGORITHMS_H_
#define _FIN_ALGORITHMS_H_

#include <cmath>
using namespace std;

double term_structure_discount_factor_vasicek(double T, double r_t, double a, double b, double sigma) {
    double B = (1 - std::exp(-a * T)) / a;
    double A = (b - std::pow(sigma, 2) / (2 * std::pow(a, 2))) * B - std::pow(sigma, 2) * std::pow(B, 2) / (4 * a);
    return std::exp(A - B * r_t);
}

#endif // _FIN_ALGORITHMS_H_