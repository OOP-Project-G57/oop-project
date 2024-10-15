#include "Cryptocurrency.h"  // Include the Cryptocurrency class header
#include <cassert>            // For using assertions to validate test results
#include <iostream>           // For input/output operations (std::cout)

// Function to test the functionality of the Cryptocurrency class
void testCryptocurrency() {
    // Create a Cryptocurrency object representing Bitcoin
    Cryptocurrency bitcoin("Bitcoin", 30000, 2);

    // Test the buy function: Add 1 Bitcoin at $35,000 each
    bitcoin.buy(1, 35000);
    assert(bitcoin.getQuantity() == 3);  // Check if quantity updated to 3
    assert(bitcoin.getPrice() == 35000); // Check if price updated to $35,000

    // Test the sell function: Sell 1 Bitcoin at $34,000
    bool sellSuccess = bitcoin.sell(1, 34000);
    assert(sellSuccess);  // Ensure the sale was successful
    assert(bitcoin.getQuantity() == 2);  // Check if quantity updated to 2

    // Print success message if all tests pass
    std::cout << "Cryptocurrency tests passed!\n";
}

// Main function to run the testCryptocurrency function
int main() {
    testCryptocurrency();  // Call the test function for Cryptocurrency class
    return 0;  // Return 0 to indicate successful execution
}
