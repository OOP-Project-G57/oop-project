#include <iostream>
#include <sstream> // For using ostringstream
#include "TransactionLog.h"

using namespace std;

int main() {
    // Create a TransactionLog object
    TransactionLog log;

    // Create some sample transactions
    Transaction transaction1("Apple Stock", "Buy", 10, 150.0, "2024-10-14");
    Transaction transaction2("Google Stock", "Sell", 5, 2500.0, "2024-10-15");
    
    // Log the transactions
    log.logTransaction(transaction1);
    log.logTransaction(transaction2);

    // Capture the output of displayLog using ostringstream
    ostringstream oss;
    log.displayLog(oss);
    
    // Define the expected output
    string expectedOutput = 
        "Transaction Log:\n"
        "Transaction - Asset: Apple Stock, Type: Buy, Quantity: 10, Price: 150, Date: 2024-10-14\n"
        "Transaction - Asset: Google Stock, Type: Sell, Quantity: 5, Price: 2500, Date: 2024-10-15\n";
    
    // Compare the actual output with the expected output
    if (oss.str() == expectedOutput) {
        cout << "TransactionLog Test passed!" << endl;
    } else {
        cout << "TransactionLog Test failed!" << endl;
        cout << "Expected:\n" << expectedOutput;
        cout << "Got:\n" << oss.str();
    }

    return 0;
}