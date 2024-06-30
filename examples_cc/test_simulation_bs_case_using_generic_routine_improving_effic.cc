void test_simulation_bs_case_using_generic_routine_improving_efficiency(){
    double S = 100; double K = 100; double r = 0.1;
    double sigma    = 0.25; double time = 1; int no_sims     = 50000;
    cout << "Black Scholes call option price = " 
	 << option_price_call_black_scholes(S,K,r,sigma,time) << endl;
    cout << "Simulated call option price     = " 
	 << derivative_price_simulate_european_option_generic(S,K,r,sigma,time, payoff_call,no_sims)
	 << endl;
    cout << "Simulated call option price, CV = " 
	 << derivative_price_simulate_european_option_generic_with_control_variate(S,K,r,sigma,time,
										   payoff_call,no_sims)
	 << endl;
    cout << "Simulated call option price, AV = " 
	 << derivative_price_simulate_european_option_generic_with_antithetic_variate(S,K,r,sigma,time,
										      payoff_call,no_sims)
	 << endl;
    cout << "Black Scholes put option price  = " << option_price_put_black_scholes(S,K,r,sigma,time) << endl;
    cout << "Simulated put option price      = " 
	 << derivative_price_simulate_european_option_generic(S,K,r,sigma,time,payoff_put,no_sims) << endl;
    cout << "Simulated put option price,  CV = " 
	 << derivative_price_simulate_european_option_generic_with_control_variate(S,K,r,sigma,time,
										   payoff_put,no_sims)
	 << endl;
    cout << "Simulated put option price,  AV = " 
	 << derivative_price_simulate_european_option_generic_with_antithetic_variate(S,K,r,sigma,time,
										      payoff_put,no_sims)
	 << endl;
};
