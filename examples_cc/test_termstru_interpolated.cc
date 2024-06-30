
void test_termstru_interpolated(){
    vector<double> times; 
    vector<double> yields; 
    times.push_back(0.1);  times.push_back(0.5);  times.push_back(1); 
    yields.push_back(0.1); yields.push_back(0.2); yields.push_back(0.3);
    times.push_back(5);    times.push_back(10);
    yields.push_back(0.4); yields.push_back(0.5);
    cout << " yields at times: " << endl;
    cout << " t=.1 " << term_structure_yield_linearly_interpolated(0.1,times,yields) << endl;
    cout << " t=0.5 " << term_structure_yield_linearly_interpolated(0.5,times,yields) << endl;
    cout << " t=1 " << term_structure_yield_linearly_interpolated(1,times,yields) << endl;
    cout << " t=3 " << term_structure_yield_linearly_interpolated(3,times,yields) << endl;
    cout << " t=5 " << term_structure_yield_linearly_interpolated(5,times,yields) << endl; 
    cout << " t=10 " << term_structure_yield_linearly_interpolated(10,times,yields) << endl;
};
