void test_term_structure_vasicek() {
    cout << "Example term structure calculation using the Vasicek term structure model" << endl;
    double r=0.05;  double a=-0.1; double b=0.1; double sigma=0.1;
    cout << " direct calculation, discount factor (t=1): " 
	 << term_structure_discount_factor_vasicek(1, r, a, b, sigma) << endl;
    term_structure_class_vasicek vc(r,a,b,sigma);
    cout << " using a term structure class " << endl;
    cout << " yield (t=1) = " << vc.yield(1) << endl;
    cout << " discount factor (t=1) = " << vc.discount_factor(1) << endl;
    cout << " forward rate (t1=1, t2=2) = " << vc.forward_rate(1,2) << endl;
}
