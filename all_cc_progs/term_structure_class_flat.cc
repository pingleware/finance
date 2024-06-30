#include "term_structure_class_flat.h"

term_structure_class_flat::term_structure_class_flat(const double& r){ R_ = r; }

double term_structure_class_flat::yield(const double& T) const { if (T>=0) return R_; return 0;};

void term_structure_class_flat::set_int_rate(const double& r) { R_ = r; };
