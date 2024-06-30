#include "test_bermudan_option.cc"
#include "test_analytical_geometric_average.cc"
#include "test_exotics_lookback.cc"
#include "test_simulate_general_european.cc"

void average_and_lookback_options_examples(){
    cout << "------------------------------------" << endl;
    cout << "Average and Lookback Options " << endl;
    cout << "------------------------------------" << endl;
    test_bermudan_option();
    test_analytical_geometric_average();
    test_exotics_lookback();
    test_simulate_general_european();
};
