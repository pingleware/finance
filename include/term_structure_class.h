#ifndef _TERM_STRUCTURE_CLASS_H_
#define _TERM_STRUCTURE_CLASS_H_

class term_structure_class {
public:
    virtual double yield(const double& t) const;
    virtual double discount_factor(const double& t) const;
    virtual double forward_rate(const double& t1, const double& t2) const;
};

#endif
