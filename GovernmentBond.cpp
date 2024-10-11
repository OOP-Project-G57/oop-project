#include "GovernmentBond.h"

GovernmentBond::GovernmentBond(std::string n, double p, int q, double ir)
    : Bond(n, p, q, ir) {}

void GovernmentBond::display(std::ostream& out) const {
    out << name << " (Government Bond) - Price: " << price 
        << ", Quantity: " << quantity 
        << ", Interest Rate: " << interestRate << "%" << std::endl;
}
