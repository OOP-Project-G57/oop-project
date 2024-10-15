#include "GovernmentBond.h"  // Include the GovernmentBond header

// Constructor: Initializes the GovernmentBond object
// Calls the base class (Bond) constructor to set common attributes
GovernmentBond::GovernmentBond(std::string n, double p, int q, double ir)
    : Bond(n, p, q, ir) {}

// Displays the bond details to the given output stream
// Includes the name, price, quantity, and interest rate of the bond
void GovernmentBond::display(std::ostream& out) const {
    out << name << " (Government Bond) - Price: " << price 
        << ", Quantity: " << quantity 
        << ", Interest Rate: " << interestRate << "%" << std::endl;
}
