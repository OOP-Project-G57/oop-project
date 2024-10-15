#ifndef GOVERNMENTBOND_H  // @Prevent multiple inclusions of this header file
#define GOVERNMENTBOND_H

#include "Bond.h"  // @Include the Bond class for inheritance

/**
 * @brief Represents a government bond asset.
 * @details This class inherits from the Bond class and provides specific 
 *          behavior related to government-issued bonds.
 */
class GovernmentBond : public Bond {
public:
    /**
     * @brief Constructor to initialize the government bond.
     * @param n The name of the government bond (e.g., "US Treasury").
     * @param p The current price of the bond.
     * @param q The quantity of the bond held.
     * @param ir The interest rate associated with the bond.
     */
    GovernmentBond(std::string n, double p, int q, double ir);

    /**
     * @brief Displays the government bond details.
     * @details Prints the bond information to the specified output stream.
     * @param out The output stream to which the bond details are displayed (e.g., std::cout).
     */
    void display(std::ostream& out) const;
};

#endif  // @End of GOVERNMENTBOND_H include guard
