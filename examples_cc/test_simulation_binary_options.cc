void test_simulation_binary_options(){
    double S=100.0; double K=100.0; double r=0.1; double sigma=0.25;
    double time=1.0;  int no_sims=5000;
    cout << " cash or nothing, Q=1: " 
	 << derivative_price_simulate_european_option_generic(S,K,r,sigma,time,
							      payoff_cash_or_nothing_call,
							      no_sims)
	 << endl;
    cout << " control_variate " 
	 << derivative_price_simulate_european_option_generic_with_control_variate(S,K,r,sigma,time,
										   payoff_cash_or_nothing_call,
										   no_sims)
	 << endl;
    cout << " antithetic_variate " 
	 << derivative_price_simulate_european_option_generic_with_antithetic_variate(S,K,r,sigma,time,
										      payoff_cash_or_nothing_call,
										      no_sims)
	 << endl;
    cout << " asset or nothing: " 
	 << derivative_price_simulate_european_option_generic(S,K,r,sigma,time,
							      payoff_asset_or_nothing_call,
							      no_sims)
	 << endl;
    cout << " control_variate " 
	 << derivative_price_simulate_european_option_generic_with_control_variate(S,K,r,sigma,time,
										   payoff_asset_or_nothing_call,
										   no_sims)
	 << endl;
    cout << " antithetic_variate " 
	 << derivative_price_simulate_european_option_generic_with_antithetic_variate(S,K,r,sigma,time,
										      payoff_asset_or_nothing_call,
										      no_sims)
	 << endl;
};
