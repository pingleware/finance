void test_bonds_price_discrete(){
    vector<double> cflows; cflows.push_back(10); cflows.push_back(10); cflows.push_back(110);
    vector<double> times;  times.push_back(1);   times.push_back(2);   times.push_back(3);
    double r=0.09;
    double B = bonds_price_discrete(times, cflows, r);
    cout << " Bond price, 9\% discretely compounded interest = " << B << endl;
    cout << " bond yield to maturity = " << bonds_yield_to_maturity_discrete(times, cflows, B) << endl;
    cout << " bond duration  = " << bonds_duration_discrete(times, cflows, B) << endl;
    cout << " bond duration modified = " << bonds_duration_modified_discrete(times, cflows, B) << endl;
    cout << " bond convexity =" << bonds_convexity_discrete(times, cflows, r) << endl;
};
