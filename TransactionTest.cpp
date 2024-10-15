#include <iostream>
#include <sstream> // For std::ostringstream
#include "Transaction.h"

using namespace std;

// Function to test the Transaction class
void testTransaction() {
    // Create a Transaction instance
    Transaction transaction("Apple Stock", "Buy", 10, 150.0, "2024-10-14");

    // Capture the output of the displayTransaction function
    ostringstream output;
    transaction.displayTransaction(output);

    // Expected output for the transaction
    string expectedOutput = "Transaction - Asset: Apple Stock, Type: Buy, Quantity: 10, Price: 150, Date: 2024-10-14\n";

    // Compare the actual output with the expected output
    if (output.str() == expectedOutput) {
        cout << "Transaction Test passed!" << endl;
    } else {
        cout << "Transaction Test failed!" << endl;
        cout << "Expected:\n" << expectedOutput;
        cout << "Got:\n" << output.str();
    }
}

int main() {
    testTransaction();
    return 0;
}
