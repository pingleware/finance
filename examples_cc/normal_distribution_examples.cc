#include "test_cumulative_normal.cc"
#include "test_random_normal.cc"

void normal_distribution_examples(){
    cout << "----------------------------------" << endl;
    cout << " Normal distribution calculations " << endl;
    cout << "----------------------------------" << endl;
    test_cumulative_normal();
    test_random_normal();
};
