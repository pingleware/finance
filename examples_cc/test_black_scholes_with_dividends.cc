void test_black_scholes_with_dividends(){
    double S = 100.0;    double K = 100.0;
    double r = 0.1;      double sigma = 0.25;
    double time=1.0;
    double dividend_yield=0.05;
    vector<double> dividend_times;     vector<double> dividend_amounts; 
    dividend_times.push_back(0.25);    dividend_amounts.push_back(2.5); 
    dividend_times.push_back(0.75);    dividend_amounts.push_back(2.5);
    cout << " european stock call option with contininous dividend = "
	 << option_price_european_call_payout(S,K,r,dividend_yield,sigma,time) << endl;
    cout << " european stock call option with discrete dividend =  "
	 << option_price_european_call_dividends(S,K,r,sigma,time,dividend_times,dividend_amounts) << endl;
};
