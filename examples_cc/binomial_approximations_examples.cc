#include "test_binomial_approximations_option_pricing.cc"
#include "test_binomial_approximations_option_price_partials.cc"
#include "test_binomial_approximations_option_price_dividends.cc"
#include "test_binomial_approximations_futures_options.cc"
#include "test_binomial_approximations_currency_options.cc"

void binomial_approximations_examples(){
    cout << "-------------------------------------" << endl;
    cout << "Binomial Approximations examples" << endl;
    cout << "-------------------------------------" << endl;
    test_binomial_approximations_option_pricing();
    test_binomial_approximations_option_price_partials();
    test_binomial_approximations_option_price_dividends();
    test_binomial_approximations_futures_options();
    test_binomial_approximations_currency_options();
};
