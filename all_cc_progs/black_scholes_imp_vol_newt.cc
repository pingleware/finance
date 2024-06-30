#include "fin_recipes.h"
#include "normdist.h"
#include <cmath>

double option_price_implied_volatility_call_black_scholes_newton(const double& S,
								 const double& K, 
								 const double& r,
								 const double& time,
								 const double& option_price) {
  double sigma_low = 1e-5;                          // check for arbitrage violations:
  double price = option_price_call_black_scholes(S,K,r,sigma_low,time);
  if (price > option_price) return 0.0;   // if price at almost zero volatility greater than price, return 0

  const int MAX_ITERATIONS = 100;
  const double ACCURACY    = 1.0e-4; 
  double t_sqrt = sqrt(time);

  double sigma = (option_price/S)/(0.398*t_sqrt);    // find initial value
  for (int i=0;i<MAX_ITERATIONS;i++){
    price = option_price_call_black_scholes(S,K,r,sigma,time);
    double diff = option_price -price;
    if (fabs(diff)<ACCURACY) return sigma;
    double d1 = (log(S/K)+r*time)/(sigma*t_sqrt) + 0.5*sigma*t_sqrt; 
    double vega = S * t_sqrt * n(d1);
    sigma = sigma + diff/vega;
  };
  return -99e10;  // something screwy happened, should throw exception
};
