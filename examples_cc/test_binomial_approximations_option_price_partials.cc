void test_binomial_approximations_option_price_partials(){
    double S = 100.0;    double K = 100.0;
    double r = 0.1;      double sigma = 0.25;
    double time=1.0;     int no_steps = 100;

    double delta, gamma, theta, vega, rho;
    option_price_partials_american_call_binomial(S,K,r, sigma, time, no_steps,
						 delta, gamma, theta, vega, rho);
    cout << " Call price partials " << endl;
    cout << "  delta = " << delta << endl;
    cout << "  gamma = " << gamma << endl;
    cout << "  theta = " << theta << endl;
    cout << "  vega  = " << vega << endl;
    cout << "  rho   = " << rho << endl;
};
