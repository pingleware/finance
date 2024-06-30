#include "test_present_value.cc"
#include "test_bonds_price_discrete.cc"

void present_value_examples(){
    cout << "----------------------------" << endl;
    cout << "Present Value and Bond Pricing Chapter " << endl;
    cout << "----------------------------" << endl;
    test_present_value();
    test_bonds_price_discrete();
};
