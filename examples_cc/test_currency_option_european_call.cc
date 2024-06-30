void test_currency_option_european_call(){
    double S = 50.0;      double K = 52.0;
    double r = 0.08;      double rf=0.05;
    double sigma = 0.2;   double time=0.5;
    cout << " european currency call option = "
	 << currency_option_price_call_european(S,K,r,rf,sigma,time) << endl;
};
