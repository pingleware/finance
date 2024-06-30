void test_binomial_approximations_currency_options(){
    double S = 50.0;      double K = 52.0;
    double r = 0.08;      double rf=0.05;
    double sigma = 0.2;   double time=0.5;

    int no_steps = 100;
    cout << " european currency option call = " 
	 << currency_option_price_call_american_binomial(S,K,r,rf,sigma,time,no_steps)  << endl;
};
