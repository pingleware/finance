#include "test_black_scholes_with_dividends.cc"
#include "test_rgw_price_am_call_div.cc"
#include "test_futures_option_price_black.cc"
#include "test_currency_option_european_call.cc"
#include "test_option_price_perpetual_american_call.cc"

void black_scholes_extensions_examples(){
    cout << "-------------------------------" << endl;
    cout << "Black Scholes extensions" << endl;
    cout << "-------------------------------" << endl;
    test_black_scholes_with_dividends();
    test_futures_option_price_black();
    test_currency_option_european_call();
    test_rgw_price_am_call_div();
    test_option_price_perpetual_american_call();
};
