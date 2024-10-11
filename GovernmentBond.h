#ifndef GOVERNMENTBOND_H
#define GOVERNMENTBOND_H

#include "Bond.h"

class GovernmentBond : public Bond {
public:
    GovernmentBond(std::string n, double p, int q, double ir);
    void display(std::ostream& out) const;
};

#endif
