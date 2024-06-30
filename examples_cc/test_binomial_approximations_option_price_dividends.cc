void test_binomial_approximations_option_price_dividends(){
    double S = 100.0;    double K = 100.0;
    double r = 0.10;      double sigma = 0.25;
    double time=1.0;
    int no_steps = 100;
    double d=0.02;
    cout << " call price with continuous dividend payout = " 
	 << option_price_call_american_binomial(S,K,r,d,sigma,time,no_steps) << endl;
    vector<double> dividend_times;      vector<double> dividend_yields;
    dividend_times.push_back(0.25);     dividend_yields.push_back(0.025);
    dividend_times.push_back(0.75);     dividend_yields.push_back(0.025);
    cout << " call price with proportial dividend yields at discrete dates = "
	 << option_price_call_american_proportional_dividends_binomial(S,K,r,sigma,time,no_steps,
								       dividend_times, dividend_yields) 
	 << endl;

    vector<double> dividend_amounts; 
    dividend_amounts.push_back(2.5);
    dividend_amounts.push_back(2.5);
    cout << " call price with proportial dividend amounts at discrete dates = "
	 << option_price_call_american_discrete_dividends_binomial(S,K,r,sigma,time,no_steps,
								   dividend_times, dividend_amounts) 
	 << endl;
};
