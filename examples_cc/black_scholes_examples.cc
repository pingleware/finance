#include "test_option_price_call_black_scholes.cc"
#include "test_black_scholes_partials_call.cc"
#include "test_black_scholes_implied_volatility.cc"

void black_scholes_examples(){
    cout << "----------------------------------------" << endl;
    cout << "Examples in Black Scholes chapter " << endl; 
    cout << "----------------------------------------" << endl;
    test_option_price_call_black_scholes();
    test_black_scholes_partials_call();
    test_black_scholes_implied_volatility();
};
