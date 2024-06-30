#include "normdist.h"

void test_random_normal(){
    cout << " 5 random uniform numbers between 0 and 1: ";
    for (int i=0;i<5;++i){ cout << " " << random_uniform_0_1(); }; cout << endl;
    cout << " 5 random normal(0,1) numbers: ";
    for (int i=0;i<5;++i){ cout << " " << random_normal(); }; cout << endl;
};
