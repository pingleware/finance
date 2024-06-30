void test_binomial_approximations_option_pricing(){
    double S = 100.0;    double K = 100.0;
    double r = 0.1;      double sigma = 0.25;
    double time=1.0;
    int no_steps = 100;
    cout << " european call = " 
	 << option_price_call_european_binomial(S,K,r,sigma,time,no_steps) 
	 << endl;
    cout << " american call = " 
	 << option_price_call_american_binomial(S,K,r,sigma,time,no_steps) 
	 << endl;
};
