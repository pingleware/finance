void test_option_price_perpetual_american_call(){
    double S=50.0;    double K=40.0;    
    double r=0.05;    double q=0.02;    
    double sigma=0.05;
    double price = option_price_american_perpetual_call(S,K,r,q,sigma); 
    cout << " perpetual call price = " <<  price << endl;
};
