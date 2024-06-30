void test_term_structure_cir(){
    cout << "Example calculations using the Cox Ingersoll Ross term structure model " << endl;
    double r = 0.05; double kappa=0.01; double sigma=0.1; double theta=0.08; double lambda=0.0;
    cout << " direct calculation, discount factor (t=1): " 
	 << term_structure_discount_factor_cir(1, r, kappa, lambda, theta, sigma) << endl;
    cout << " using a class " << endl;
    term_structure_class_cir cir(r,kappa,lambda,theta,sigma);
    cout << " yield (t=1) = " << cir.yield(1) << endl;
    cout << " discount factor (t=1) = " << cir.discount_factor(1) << endl;
    cout << " forward (t1=1, t2=2) = "  << cir.forward_rate(1,2) << endl;
};
