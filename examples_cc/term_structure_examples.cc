#include "test_termstru_transforms.cc"
#include "test_term_structure_class_flat.cc"
#include "test_termstru_interpolated.cc"
#include "test_term_structure_class_interpolated.cc"
#include "test_term_structure_class_bond_calculations.cc"

void term_structure_examples(){
    cout << "--------------------------------------------" << endl;
    cout << " Term structure of interest rates examples  " << endl;
    cout << "--------------------------------------------" << endl;
    test_termstru_transforms();
    test_term_structure_class_flat();
    test_termstru_interpolated();
    test_term_structure_class_interpolated();
    test_term_structure_class_bond_calculations();
};
