#include <cmath>
#include "fin_recipes.h"

double option_price_implied_volatility_call_black_scholes_bisections(const double& S,
								     const double& X,
								     const double& r,
								     const double& time,
								     const double& option_price){
    double sigma_low=0.0001; // check for arbitrage violations: 
    double price = option_price_call_black_scholes(S,X,r,sigma_low,time);    
    if (price>option_price) return 0.0;  // if price at almost zero volatility greater than price, return 0
  
    // simple binomial search for the implied volatility.
    // relies on the value of the option increasing in volatility
    const double ACCURACY = 1.0e-5; // make this smaller for higher accuracy
    const int MAX_ITERATIONS = 100;
    const double HIGH_VALUE = 1e10;
    const double ERROR = -1e40;
  
    // want to bracket sigma. first find a maximum sigma by finding a sigma
    // with a estimated price higher than the actual price.
    double sigma_high=0.3;
    price = option_price_call_black_scholes(S,X,r,sigma_high,time);
    while (price < option_price) {  
	sigma_high = 2.0 * sigma_high; // keep doubling.
	price = option_price_call_black_scholes(S,X,r,sigma_high,time);
	if (sigma_high>HIGH_VALUE) return ERROR; // panic, something wrong.
    };
    for (int i=0;i<MAX_ITERATIONS;i++){
	double sigma = (sigma_low+sigma_high)*0.5;
	price = option_price_call_black_scholes(S,X,r,sigma,time);
	double test =  (price-option_price);
	if (fabs(test)<ACCURACY) { return sigma; };
	if (test < 0.0) { sigma_low = sigma; }
	else { sigma_high = sigma; }
    };
    return ERROR;
};
