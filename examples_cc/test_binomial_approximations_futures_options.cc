void test_binomial_approximations_futures_options(){
    double F = 50.0;    double K = 45.0;
    double r = 0.08;    double sigma = 0.2;
    double time=0.5;
    int no_steps=100;
    cout << " european futures call option = "
	 << futures_option_price_call_american_binomial(F,K,r,sigma,time,no_steps) << endl;
};
