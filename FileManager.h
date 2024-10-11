#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include "PortfolioManager.h"
#include "Transaction.h"

/**
 * @class FileManager
 * @brief Manages file operations for saving and loading portfolio and transactions.
 * 
 * This class provides methods to save a portfolio and transaction log to files
 * and to load them back into the respective objects.
 */
class FileManager {
public:
    /**
     * @brief Saves the current portfolio to a file.
     * 
     * Writes each asset's name, price, and quantity to the specified file.
     * 
     * @param manager The PortfolioManager object containing the portfolio.
     * @param filename The name of the file to save the portfolio to.
     */
    void savePortfolio(const PortfolioManager& manager, const std::string& filename);

    /**
     * @brief Loads a portfolio from a file.
     * 
     * Reads asset details (name, price, quantity) from the file and adds them to the portfolio.
     * 
     * @param manager The PortfolioManager object to load the portfolio into.
     * @param filename The name of the file to load the portfolio from.
     */
    void loadPortfolio(PortfolioManager& manager, const std::string& filename);

    /**
     * @brief Saves the transaction log to a file.
     * 
     * Writes the transaction log to the specified file.
     * 
     * @param log The TransactionLog object containing the transaction history.
     * @param filename The name of the file to save the transaction log to.
     */
    void saveTransactionLog(const TransactionLog& log, const std::string& filename);

    /**
     * @brief Loads the transaction log from a file.
     * 
     * Reads transaction history from the file and displays it to the console (simulated loading).
     * 
     * @param log The TransactionLog object to load the data into.
     * @param filename The name of the file to load the transaction log from.
     */
    void loadTransactionLog(TransactionLog& log, const std::string& filename);
};

#endif // FILEMANAGER_H
