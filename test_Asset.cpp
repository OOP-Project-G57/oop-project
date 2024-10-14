#include "Asset.h"  // Include the Asset class header
#include "Stock.h"  // Include the Stock class header, derived from Asset
#include <cassert>  // For using assertions to validate test results
#include <iostream> // For input/output operations (std::cout)

// Function to test the Asset class functionality using a Stock object
void testAsset() {
    // Create a Stock object representing Apple with a price of $150 and quantity of 10
    Stock apple("AAPL", 150, 10);

    // Validate the name, price, and quantity using assertions
    assert(apple.getName() == "AAPL");   // Check if the name is correct
    assert(apple.getPrice() == 150);     // Check if the price is correct
    assert(apple.getQuantity() == 10);   // Check if the quantity is correct

    // Print success message if all assertions pass
    std::cout << "Asset (via Stock) tests passed!\n";
}

// Main function to run the testAsset function
int main() {
    testAsset();  // Call the test function for Asset (via Stock)
    return 0;  // Return 0 to indicate successful execution
}
