void test_term_structure_cubic_spline(){
    cout << "Example term structure calculations using a cubic spline " << endl;
    double b=0.1;  double c=0.1; double d=-0.1;
    vector<double> f;     f.push_back(0.01);  f.push_back(0.01);  f.push_back(-0.01);
    vector<double> knots; knots.push_back(2); knots.push_back(7); knots.push_back(12); 
    cout << " direct calculation, discount factor (t=1) "
	 << term_structure_discount_factor_cubic_spline(1,b,c,d,f,knots) << endl;
    cout << " Using a term structure class " << endl;
    term_structure_class_cubic_spline cs(b,c,d,f,knots);
    cout << " yield (t=1) = " << cs.yield(1) << endl;
    cout << " discount factor (t=1) = " << cs.discount_factor(1) << endl;
    cout << " forward (t1=1, t2=2) = "  << cs.forward_rate(1,2) << endl;
};
