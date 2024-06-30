void test_simulation_bs_case_using_generic_routine(){
    double S  = 100; double X = 100; double r = 0.1;
    double sigma = 0.25; double time  = 1.0;  int no_sims     = 50000;
    cout << "Black Scholes call option price = " << option_price_call_black_scholes(S,X,r,sigma,time) << endl;
    cout << "Simulated call option price     = " 
	 << derivative_price_simulate_european_option_generic(S,X,r,sigma,time,payoff_call,no_sims)
	 << endl;
    cout << "Black Scholes put option price  = " << option_price_put_black_scholes(S,X,r,sigma,time) << endl;
    cout << "Simulated put option price      = " 
	 << derivative_price_simulate_european_option_generic(S,X,r,sigma,time,payoff_put,no_sims)
	 << endl;
};
