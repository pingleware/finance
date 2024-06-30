#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

double option_price_delta_american_call_binomial(const double& S,
						 const double& X,  
						 const double& r,  
						 const double& sigma,
						 const double& t, 
						 const int& no_steps){ // steps in binomial
   vector<double> prices (no_steps+1);
   vector<double> call_values (no_steps+1);
   double R = exp(r*(t/no_steps));
   double Rinv = 1.0/R;
   double u = exp(sigma*sqrt(t/no_steps));
   double d = 1.0/u;
   double uu= u*u;
   double pUp   = (R-d)/(u-d);
   double pDown = 1.0 - pUp;
   prices[0] = S*pow(d, no_steps);
   int i;
   for (i=1; i<=no_steps; ++i) prices[i] = uu*prices[i-1];
   for (i=0; i<=no_steps; ++i) call_values[i] = max(0.0, (prices[i]-X));
   for (int CurrStep=no_steps-1 ; CurrStep>=1; --CurrStep) {
      for (i=0; i<=CurrStep; ++i)   {
	 prices[i] = d*prices[i+1];
	 call_values[i] = (pDown*call_values[i]+pUp*call_values[i+1])*Rinv;
	 call_values[i] = max(call_values[i], prices[i]-X);        // check for exercise
      };
   }; 
   double delta = (call_values[1]-call_values[0])/(S*u-S*d);
   return delta;
};
