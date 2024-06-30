void test_term_structure_nelson_siegel(){
    double beta0=0.01;  double beta1=0.01; double beta2=0.01; double lambda=5.0;
    double t=1.0;
    cout << "Example calculations using the Nelson Siegel term structure approximation" << endl;
    cout << " direct calculation, yield = " 
	 << term_structure_yield_nelson_siegel(t,beta0,beta1,beta2,lambda) << endl;

    term_structure_class_nelson_siegel ns(beta0,beta1,beta2,lambda);
    cout << " using a term structure class" << endl;
    cout << " yield (t=1) = " << ns.yield(t) << endl;
    cout << " discount factor (t=1) = " << ns.discount_factor(t) << endl;
    cout << " forward rate (t1=1, t2=2) = " << ns.forward_rate(1,2) << endl;
};
