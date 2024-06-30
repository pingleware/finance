#include <cmath>     // standard mathematical functions
#include <algorithm>     // define the max() function
using namespace std;
#include "normdist.h"   // definition of random number generator

double
option_price_call_european_simulated( const double& S, // price of underlying
				      const double& X, // exercise price
				      const double& r, // risk free interest rate
				      const double& sigma,  // volatility of underlying
				      const double& time, // time to maturity (in years)
				      const int& no_sims){ // number of simulations
    double R = (r - 0.5 * pow(sigma,2))*time;
    double SD = sigma * sqrt(time);
    double sum_payoffs = 0.0;
    for (int n=1; n<=no_sims; n++) {
	double S_T = S* exp(R + SD * random_normal());
	sum_payoffs += max(0.0, S_T-X);
    };
    return exp(-r*time) * (sum_payoffs/double(no_sims));
};
