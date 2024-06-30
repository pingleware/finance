#include <cmath>
#include <vector>
using namespace std;
#include "normdist.h"

vector<double> 
simulate_lognormally_distributed_sequence(const double& S,  // current value of underlying
					  const double& r,  // interest rate
					  const double& sigma,  // volatitily 
					  const double& time,  // time to final date
					  const int& no_steps){  // number of steps 
    vector<double> prices(no_steps);
    double delta_t = time/no_steps;
    double R = (r-0.5*pow(sigma,2))*delta_t;
    double SD = sigma * sqrt(delta_t);
    double S_t = S;                       // initialize at current price
    for (int i=0;  i<no_steps; ++i) {   
	S_t = S_t * exp(R + SD * random_normal());
	prices[i]=S_t;
    };
    return prices;
};
