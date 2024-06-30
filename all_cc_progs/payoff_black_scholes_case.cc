#include <algorithm>
using namespace std;

double payoff_call(const double& price, const double& X){
    return max(0.0,price-X); 
};

double payoff_put (const double& price, const double& X) { 
    return max(0.0,X-price); 
};
