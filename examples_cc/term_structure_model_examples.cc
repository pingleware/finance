#include "test_term_structure_nelson_siegel.cc"
#include "test_term_structure_cir.cc"
#include "test_term_structure_cubic_spline.cc"
#include "test_term_structure_vasicek.cc"

void term_structure_model_examples(){
    cout << "----------------------------" << endl;
    cout << "Further term structure models " << endl;
    cout << "----------------------------" << endl;
    test_term_structure_nelson_siegel(); 
    test_term_structure_cir();
    test_term_structure_cubic_spline();
    test_term_structure_vasicek(); 
}; 
