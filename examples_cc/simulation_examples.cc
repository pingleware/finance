#include "test_simulation_pricing.cc"
#include "test_simulation_pricing_delta.cc"
#include "test_simulation_bs_case_using_generic_routine.cc"
#include "test_simulation_bs_case_using_generic_routine_improving_effic.cc"
#include "test_simulation_binary_options.cc"

void simulation_examples(){
    cout << "--------------------------" << endl;
    cout << " Simulation examples " << endl;
    cout << "--------------------------" << endl;
    test_simulation_pricing();
    test_simulation_pricing_delta(); 
    test_simulation_bs_case_using_generic_routine();
    test_simulation_bs_case_using_generic_routine_improving_efficiency();
    test_simulation_binary_options();
};
