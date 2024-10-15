#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include "PortfolioManager.h"
#include "Transaction.h"
#include "debug.h"

/**
 * @brief Manages saving and loading portfolios and transaction logs.
 * 
 * The FileManager class is responsible for handling file I/O for portfolio
 * and transaction log data. It provides methods to save and load portfolios
 * and transaction logs to/from files.
 */
class FileManager {
public:
    /**
     * @brief Saves the portfolio to a file.
     * 
     * This method writes the details of each asset in the PortfolioManager
     * to the specified file.
     * 
     * @param manager The PortfolioManager object containing assets.
     * @param filename The name of the file to save the portfolio.
     */
    void savePortfolio(const PortfolioManager& manager, const std::string& filename);

    /**
     * @brief Loads the portfolio from a file.
     * 
     * This method reads the asset details from the specified file and adds
     * them to the PortfolioManager object.
     * 
     * @param manager The PortfolioManager object to load the assets into.
     * @param filename The name of the file to load the portfolio from.
     */
    void loadPortfolio(PortfolioManager& manager, const std::string& filename);

    /**
     * @brief Saves the transaction log to a file.
     * 
     * This method writes all the transaction details from the TransactionLog
     * to the specified file.
     * 
     * @param log The TransactionLog object containing transactions.
     * @param filename The name of the file to save the transaction log.
     */
    void saveTransactionLog(const TransactionLog& log, const std::string& filename);

    /**
     * @brief Loads the transaction log from a file.
     * 
     * This method reads the transaction details from the specified file and
     * adds them to the TransactionLog object.
     * 
     * @param log The TransactionLog object to load the transactions into.
     * @param filename The name of the file to load the transaction log from.
     */
    void loadTransactionLog(TransactionLog& log, const std::string& filename);
};

#endif

