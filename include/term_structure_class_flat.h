#ifndef _TERM_STRUCTURE_CLASS_FLAT_ 
#define _TERM_STRUCTURE_CLASS_FLAT_ 

#include "term_structure_class.h"

class term_structure_class_flat : public term_structure_class {
private: 
    double R_;                              // interest rate
public:
    term_structure_class_flat(const double& r);
    virtual double yield(const double& t) const;
    void set_int_rate(const double& r);
};

#endif
