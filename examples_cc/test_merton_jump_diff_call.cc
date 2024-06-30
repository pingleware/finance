#include <cmath>

void test_merton_jump_diff_call(){
    double S=100; 
    double K=100;
    double r=0.05;
    double sigma=0.3; 
    double time_to_maturity=1;
    double lambda=0.5;
    double kappa=0.5;
    double delta=0.5;
    cout << " Merton Jump diffusion call = " 
	 << option_price_call_merton_jump_diffusion(S,K,r,sigma,time_to_maturity,lambda,kappa,delta)
	 << endl;
};
