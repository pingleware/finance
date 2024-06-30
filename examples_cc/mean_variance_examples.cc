#include "test_mean_variance_calculations.cc"
#include "test_mean_variance_portfolio_calculation.cc"

void mean_variance_examples() {
    cout << "-------------------------------" << endl;
    cout << "Mean Variance Examples " << endl;
    cout << "-------------------------------" << endl;
    test_mean_variance_calculations();
    test_mean_variance_portfolio_calculation();
};
