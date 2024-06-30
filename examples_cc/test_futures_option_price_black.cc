void test_futures_option_price_black(){
    double F = 50.0;    double K = 45.0;
    double r = 0.08;    double sigma = 0.2;
    double time=0.5;
    cout << " european futures call option = "
	 << futures_option_price_put_european_black(F,K,r,sigma,time) << endl;
};
