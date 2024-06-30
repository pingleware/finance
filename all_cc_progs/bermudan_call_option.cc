#include <cmath>                 // standard C mathematical library
#include <algorithm>             // defines the max() operator
#include <vector>                // STL vector templates
using namespace std;
    
double option_price_call_bermudan_binomial( const double& S,     // spot price
					    const double& X,     // exercice price
					    const double& r,     // interest rate
					    const double& q,     // continous payout
					    const double& sigma, // volatility
					    const double& time,     // time to maturity
					    const vector<double>& potential_exercise_times,
					    const int& steps) {    // no steps in binomial tree
    double delta_t = time/steps;
    double R = exp(r*delta_t);            // interest rate for each step
    double Rinv = 1.0/R;                    // inverse of interest rate
    double u = exp(sigma*sqrt(delta_t));    // up movement
    double uu = u*u;
    double d = 1.0/u;
    double p_up = (exp((r-q)*(delta_t))-d)/(u-d);
    double p_down = 1.0-p_up;
    vector<double> prices(steps+1);       // price of underlying
    vector<double> call_values(steps+1);       // value of corresponding call 

    vector<int> potential_exercise_steps; // create list of steps at which exercise may happen
    for (int i=0;i<potential_exercise_times.size();++i){
	double t = potential_exercise_times[i];
	if ( (t>0.0)&&(t<time) ) {
	    potential_exercise_steps.push_back(int(t/delta_t));
	};
    };
    prices[0] = S*pow(d, steps);  // fill in the endnodes.
    for (int i=1; i<=steps; ++i) prices[i] = uu*prices[i-1];
    for (int i=0; i<=steps; ++i) call_values[i] = max(0.0, (prices[i]-X));
    for (int step=steps-1; step>=0; --step) {
	bool check_exercise_this_step=false;
	for (int j=0;j<potential_exercise_steps.size();++j){
	    if (step==potential_exercise_steps[j]) { check_exercise_this_step=true; };
	};
	for (int i=0; i<=step; ++i) {
	    call_values[i] = (p_up*call_values[i+1]+p_down*call_values[i])*Rinv;
	    prices[i] = d*prices[i+1];
	    // check if there is potential for exercise at this step
	    if (check_exercise_this_step) call_values[i] = max(call_values[i],prices[i]-X); 
	};
    };
    return call_values[0];
};
