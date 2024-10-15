#include "Bond.h"  // Include the Bond class header
#include <cassert>  // For using assertions to validate test results
#include <iostream> // For input/output operations (std::cout)

// Function to test the functionality of the Bond class
void testBond() {
    // Create a Bond object with name, price, quantity, and interest rate
    Bond govBond("Gov Bond", 1000, 5, 3.5);

    // Test the buy function: Add 3 bonds at a price of $1050 each
    govBond.buy(3, 1050);
    assert(govBond.getQuantity() == 8);  // Verify if quantity updated to 8
    assert(govBond.getPrice() == 1050);  // Verify if price updated to $1050

    // Test the sell function: Sell 2 bonds at a price of $1030 each
    bool sellSuccess = govBond.sell(2, 1030);
    assert(sellSuccess);  // Ensure the sale was successful
    assert(govBond.getQuantity() == 6);  // Verify if quantity updated to 6

    // Print success message if all tests pass
    std::cout << "Bond tests passed!\n";
}

// Main function to run the testBond function
int main() {
    testBond();  // Call the test function for the Bond class
    return 0;  // Return 0 to indicate successful execution
}
