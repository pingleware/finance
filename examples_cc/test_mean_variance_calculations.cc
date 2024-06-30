#include "newmat.h"
#include "mv_calc.h"
void test_mean_variance_calculations(){
    cout << "Simple example of mean variance calculations " << endl;
    Matrix e(2,1); 
    e.element(0,0)=0.05; e.element(1,0)=0.1;
    Matrix V(2,2);
    V.element(0,0)=1.0; V.element(1,0)=0.0;
    V.element(0,1)=0.0; V.element(1,1)=1.0;
    Matrix w(2,1);
    w.element(0,0)=0.5;
    w.element(1,0)=0.5;
    cout << " mean "     << mv_calculate_mean(e,w)     << endl;
    cout << " variance " << mv_calculate_variance(V,w) << endl;
    cout << " stdev "    << mv_calculate_st_dev(V,w)   << endl;
};
