void test_option_price_call_black_scholes(){
    double S = 50; double K = 50; double r = 0.10;
    double sigma = 0.30; double time=0.50;
    cout << " Black Scholes call price = ";
    cout << option_price_call_black_scholes(S, K , r, sigma, time) << endl;
};
