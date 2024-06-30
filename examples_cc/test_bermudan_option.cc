void test_bermudan_option(){
    double S=80;         double K=100;          double r = 0.20;
    double time = 1.0;   double sigma = 0.25;
    int steps = 500;
    double q=0.0;
    vector<double> potential_exercise_times;  potential_exercise_times.push_back(0.25); 
    potential_exercise_times.push_back(0.5);  potential_exercise_times.push_back(0.75);
    cout << " Bermudan put price = " 
	 << option_price_put_bermudan_binomial(S,K,r,q,sigma,time,potential_exercise_times,steps)
	 << endl;
};
