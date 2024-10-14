#ifndef GOVERNMENTBOND_H  // Prevent multiple inclusions
#define GOVERNMENTBOND_H

#include "Bond.h"  // Include the Bond class

// GovernmentBond class inherits from Bond
class GovernmentBond : public Bond {
public:
    // Constructor to initialize the government bond
    GovernmentBond(std::string n, double p, int q, double ir);

    // Displays bond details to the given output stream
    void display(std::ostream& out) const;
};

#endif  // End of include guard
