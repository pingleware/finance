void test_black_scholes_partials_call(){
    cout  << " Option price partial derivatives, call option using Black Scholes " << endl;
    double S = 50; double K = 50; double r = 0.10;
    double sigma = 0.30; double time=0.50;
    double Delta, Gamma, Theta, Vega, Rho;
    option_price_partials_call_black_scholes(S,K,r,sigma, time,
					     Delta, Gamma, Theta, Vega, Rho);
    cout << "  Delta = " << Delta << endl;
    cout << "  Gamma = " << Gamma << endl;
    cout << "  Theta = " << Theta << endl;
    cout << "  Vega  = " << Vega << endl;
    cout << "  Rho   = " << Rho << endl;
};
