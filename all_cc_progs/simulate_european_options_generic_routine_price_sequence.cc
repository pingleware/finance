#include <cmath>
using namespace std;
#include "fin_recipes.h"

double 
derivative_price_simulate_european_option_generic(const double& S, // price of underlying
						  const double& X, // used by user provided payoff function 
						  const double& r, // risk free interest rate
						  const double& sigma, // volatility
						  const double& time, // time to maturity
						  double payoff(const vector<double>& prices,
								const double& X), 
						  // user provided function
						  const int& no_steps, // number of steps in generated price sequence
						  const int& no_sims) { // number of simulations to run
    double sum_payoffs=0;
    for (int n=0; n<no_sims; n++) {
	vector<double>prices = simulate_lognormally_distributed_sequence(S,r,sigma,time,no_steps);
	sum_payoffs += payoff(prices,X);
    };
    return exp(-r*time) * (sum_payoffs/no_sims); 
};
