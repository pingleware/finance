#include "fin_recipes.h"
 
double term_structure_class::forward_rate(const double& t1, const double& t2) const{
   double d1 = discount_factor(t1);
   double d2 = discount_factor(t2);
   return term_structure_forward_rate_from_discount_factors(d1,d2,t2-t1);
};

double term_structure_class::yield(const double& t) const{
    return term_structure_yield_from_discount_factor(discount_factor(t),t);
};

double term_structure_class::discount_factor(const double& t) const {
    return term_structure_discount_factor_from_yield(yield(t),t);
};
