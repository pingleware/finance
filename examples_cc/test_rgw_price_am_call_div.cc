void test_rgw_price_am_call_div(){
    double S = 100.0;    double K = 100.0;    
    double r = 0.1;      double sigma = 0.25; 
    double tau = 1.0;    double tau1 = 0.5;
    double D1 = 10.0;
    cout << " american call price with one dividend = " 
	 << option_price_american_call_one_dividend(S,K,r,sigma,tau,D1, tau1)<< endl;
};
