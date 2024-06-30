void test_exotics_lookback(){
    double S=100; double Smin=S; double q = 0; double r = 0.06;
    double sigma = 0.346; double time = 1.0;
    cout << " Lookback call price = " 
	 << option_price_european_lookback_call(S,Smin,r,q,sigma,time) << endl;
};
