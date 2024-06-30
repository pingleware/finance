void test_simulation_pricing() { 
    double S=100.0;  double K=100.0; double r=0.1; double sigma=0.25;
    double time=1.0; int no_sims=5000;
    cout << " call:  black scholes price = "  << option_price_call_black_scholes(S,K,r,sigma,time) << endl;
    cout << "        simulated price     = "  
	 << option_price_call_european_simulated(S,K,r,sigma,time,no_sims) << endl;
    cout << " put:  black scholes price = " << option_price_put_black_scholes(S,K,r,sigma,time) << endl;
    cout << "       simulated price     = " 
	 << option_price_put_european_simulated(S,K,r,sigma,time, no_sims)  << endl;
};
