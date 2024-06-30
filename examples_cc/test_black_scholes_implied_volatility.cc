void test_black_scholes_implied_volatility(){
    double S = 50; double K = 50; double r = 0.10; double time=0.50;
    double C=2.5;
    cout << " Black Scholes implied volatility using Newton search = ";
    cout << option_price_implied_volatility_call_black_scholes_newton(S,K,r,time,C) << endl;
    cout << " Black Scholes implied volatility using bisections = ";
    cout << option_price_implied_volatility_call_black_scholes_bisections(S,K,r,time,C) << endl;
};
