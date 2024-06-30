
void test_term_structure_class_interpolated(){
    vector<double> times;     times.push_back(0.1);     
    vector<double> spotrates; spotrates.push_back(0.05);
    times.push_back(1);       times.push_back(5);
    spotrates.push_back(0.07);spotrates.push_back(0.08);
    term_structure_class_interpolated ts(times,spotrates);
    double t1=1;
    cout << "discount factor t1 = " << t1 << ":" << ts.discount_factor(t1) << endl;
    double t2=2;
    cout << "discount factor t2 = " << t2 << ":" << ts.discount_factor(t2) << endl;
    cout << "spot rate t = " << t1 << ":" << ts.yield(t1) << endl;
    cout << "spot rate t = " << t2 << ":" << ts.yield(t2) << endl;
    cout << "forward rate from t1= " << t1 << " to t2= " << t2 << ":" << ts.forward_rate(t1,t2) <<endl;
};

