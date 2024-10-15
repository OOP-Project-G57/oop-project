#pragma once

#include <vector>
#include "Transaction.h"

using namespace std;

/**
 * @brief Manages a log of transactions.
 */
class TransactionLog {
private:
    /**
     * @brief Private member variable to store transactions
     */
    vector<Transaction> transactions;

public:

    /**
     * @brief Returns a const reference to the transactions vector.
     */
    const std::vector<Transaction>& getTransactions() const;

    /**
     * @brief Logs a new transaction into the log.
     * 
     * @param transaction The transaction to log.
     */
    void logTransaction(const Transaction& transaction);

    /**
     * @brief Clears the transaction log.
     */
    void clear();  

    /**
     * @brief Displays the transaction log to the console.
     */
    void displayLog() const;

    /**
     * @brief Displays the transaction log to a specified output stream.
     * 
     * @param out The output stream to display the log (e.g., cout, ofstream).
     * @param useColor If true, display the log with color formatting.
     */
    void displayLog(ostream& out, bool useColor) const;
};