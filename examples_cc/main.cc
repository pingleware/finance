#include <vector>
#include <iostream.h>
#include "..\all_cc_progs\term_structure_class_flat.h"

double bonds_price(const vector<double>& cashflow_times,
		   const vector<double>& cashflows,
                   const double& r);

void main()
{
   vector <double> times;
   times.push_back(1);
   times.push_back(2);

   vector <double> cashFlows;
   cashFlows.push_back(10);
   cashFlows.push_back(110);

   double tsflat = 0.1;

   cout << "price = " << bonds_price(times,cashFlows,tsflat) << endl;
}
