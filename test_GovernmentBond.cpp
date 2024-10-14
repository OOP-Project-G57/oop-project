#include "GovernmentBond.h"  // Include the GovernmentBond class header
#include <cassert>            // For using assertions to validate test results
#include <iostream>           // For input/output operations (std::cout)

// Function to test the functionality of the GovernmentBond class
void testGovernmentBond() {
    // Create a GovernmentBond object with name, price, quantity, and interest rate
    GovernmentBond gbond("US Treasury", 1000, 10, 2.5);

    // Test the buy function: Add 5 bonds at $1020 each
    gbond.buy(5, 1020);
    assert(gbond.getQuantity() == 15);  // Check if quantity updated to 15
    assert(gbond.getPrice() == 1020);   // Check if price updated to $1020

    // Test the sell function: Sell 3 bonds at $1015 each
    bool sellSuccess = gbond.sell(3, 1015);
    assert(sellSuccess);  // Ensure the sale was successful
    assert(gbond.getQuantity() == 12);  // Check if quantity updated to 12

    // Print success message if all tests pass
    std::cout << "Government Bond tests passed!\n";
}

// Main function to run the testGovernmentBond function
int main() {
    testGovernmentBond();  // Call the test function for GovernmentBond class
    return 0;  // Return 0 to indicate successful execution
}
