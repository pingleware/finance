#include "fin_recipes.h"
#include "normdist.h"
#include <cmath>

double warrant_price_adjusted_black_scholes(const double& S,  // current stock price
					    const double& K,  // strike price
					    const double& r,  // interest rate
					    const double& sigma, // volatility 
					    const double& time, // time to maturity
					    const double& m, // number of warrants outstanding
					    const double& n){ // number of shares outstanding
    const double epsilon=0.00001;
    double time_sqrt = sqrt(time);
     double w = (n/(n+m))*option_price_call_black_scholes(S,K,r,sigma,time);
    double g = w-(n/(n+m))*option_price_call_black_scholes(S+(m/n)*w,K,r,sigma,time);
    while (fabs(g)>epsilon) {
	double d1 = (log((S+(m/n))/K)+r*time)/(sigma*time_sqrt)+0.5*sigma*time_sqrt; 
	double gprime = 1-(m/n)*N(d1);
	w=w-g/gprime;
	g = w-(n/(n+m))*option_price_call_black_scholes(S+(m/n)*w,K,r,sigma,time);
    };
    return w;
};
