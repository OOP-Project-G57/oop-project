#include <iostream>
#include <sstream>  // For capturing output streams
#include "TransactionLog.h"
#include "Transaction.h"

using namespace std;

/**
 * @brief Unit test for TransactionLog class
 */
void testTransactionLog() {
    // Create a TransactionLog object
    TransactionLog log;

    // Create some Transaction objects
    Transaction t1("AAPL", "buy", 100, 150.50, "2024-10-12");
    Transaction t2("GOOGL", "sell", 50, 2800.75, "2024-10-13");
    Transaction t3("TSLA", "buy", 25, 900.30, "2024-10-14");

    // Log the transactions
    log.logTransaction(t1);
    log.logTransaction(t2);
    log.logTransaction(t3);

    // Capture the output using stringstream
    stringstream output;
    log.displayLog(output, false);

    // Check if the output contains all 3 transactions
    string logContent = output.str();
    if (logContent.find("AAPL") != string::npos &&
        logContent.find("GOOGL") != string::npos &&
        logContent.find("TSLA") != string::npos) {
        cout << "Test 1 Passed: All transactions are logged and displayed correctly." << endl;
    } else {
        cout << "Test 1 Failed: Transactions are not displayed correctly." << endl;
    }

    // Clear the transaction log
    log.clear();

    // Capture the output again after clearing
    stringstream emptyOutput;
    log.displayLog(emptyOutput, false);

    // Check if the log is empty after clearing
    if (emptyOutput.str().find("AAPL") == string::npos &&
        emptyOutput.str().find("GOOGL") == string::npos &&
        emptyOutput.str().find("TSLA") == string::npos) {
        cout << "Test 2 Passed: Transaction log is empty after clearing." << endl;
    } else {
        cout << "Test 2 Failed: Transaction log is not empty after clearing." << endl;
    }

    // Log transactions again for color test
    log.logTransaction(t1);
    log.logTransaction(t2);

    // Display the transaction log with color (no capture here, just display to console)
    cout << "\nDisplaying Transaction Log (with color):" << endl;
    log.displayLog(cout, true);

    // Final test passed message
    cout << "\nAll tests completed." << endl;
}

int main() {
    // Run the TransactionLog unit test
    testTransactionLog();

    return 0;
}