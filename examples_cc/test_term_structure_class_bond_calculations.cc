void test_term_structure_class_bond_calculations(){
  vector <double> times;
  times.push_back(1);
  times.push_back(2);

  vector <double> cashflows;
  cashflows.push_back(10);
  cashflows.push_back(110);

  term_structure_class_flat tsflat(0.1);

  cout << " price = "  <<  bonds_price (times, cashflows, tsflat)  << endl;
  cout << " duration = "  <<  bonds_duration(times, cashflows, tsflat) << endl;
  cout << " convexity = "  <<  bonds_convexity(times, cashflows, tsflat) << endl;
};
