#include "Stock.h"      // Include the Stock class header
#include <cassert>       // For using assertions to validate test results
#include <iostream>      // For input/output operations (std::cout)

// Function to test the functionality of the Stock class
void testStock() {
    // Create a Stock object representing Apple stock with 10 shares at $150 each
    Stock apple("AAPL", 150, 10);

    // Test the buy function: Add 5 shares at a price of $200 each
    apple.buy(5, 200);
    assert(apple.getQuantity() == 15);  // Check if the quantity is updated to 15
    assert(apple.getPrice() == 200);    // Check if the price is updated to $200

    // Test the sell function: Sell 5 shares at a price of $180 each
    bool sellSuccess = apple.sell(5, 180);
    assert(sellSuccess);  // Ensure the sale was successful
    assert(apple.getQuantity() == 10);  // Check if the quantity is updated to 10

    // If all tests pass, print a success message
    std::cout << "Stock tests passed!\n";
}

// Main function to run the testStock function
int main() {
    testStock();  // Call the test function for Stock class
    return 0;     // Return 0 to indicate successful execution
}
