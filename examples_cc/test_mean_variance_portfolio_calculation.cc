#include "mv_calc.h"

void test_mean_variance_portfolio_calculation(){
    cout << "Testing portfolio calculation " << endl;
    Matrix e(2,1); 
    e.element(0,0)=0.05; e.element(1,0)=0.1;
    Matrix V(2,2);
    V.element(0,0)=1.0; V.element(1,0)=0.0;
    V.element(0,1)=0.0; V.element(1,1)=1.0;
    double r=0.075;
    Matrix w = mv_calculate_portfolio_given_mean_unconstrained(e,V,r);
    cout << " suggested portfolio:  ";
    cout << " w1 = " << w.element(0,0) << " w2 = " << w.element(1,0) << endl;
};
