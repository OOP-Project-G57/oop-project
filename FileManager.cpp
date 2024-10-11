#include "FileManager.h"
#include <fstream>
#include <iostream>

using namespace std;

/**
 * @brief Saves the portfolio to a file.
 * 
 * Opens the file for writing. If successful, iterates through each asset in the
 * portfolio and writes the asset's name, price, and quantity to the file.
 * 
 * @param manager The PortfolioManager object containing assets.
 * @param filename The file where the portfolio will be saved.
 */
void FileManager::savePortfolio(const PortfolioManager& manager, const string& filename) {
    ofstream file(filename);
    
    // Check if the file is successfully opened
    if (file) {
        // Iterate through the portfolio and save each asset
        for (const auto& pair : manager.getPortfolio()) {
            const Asset* asset = pair.second;
            file << asset->getName() << " " << asset->getPrice() << " " << asset->getQuantity() << endl;
        }
        cout << "Portfolio saved to " << filename << endl;
    } else {
        cerr << "Error saving portfolio to " << filename << endl;
    }
}

/**
 * @brief Loads the portfolio from a file.
 * 
 * Opens the file for reading. If successful, clears the existing portfolio and
 * loads each asset from the file by reading its name, price, and quantity.
 * 
 * @param manager The PortfolioManager object to load the portfolio into.
 * @param filename The file from which the portfolio will be loaded.
 */
void FileManager::loadPortfolio(PortfolioManager& manager, const string& filename) {
    ifstream file(filename);
    
    // Check if the file is successfully opened
    if (file) {
        manager.clearPortfolio();  // Clear the existing portfolio
        string assetName;
        double price;
        int quantity;
        
        // Read each asset from the file and add it to the portfolio
        while (file >> assetName >> price >> quantity) {
            manager.addAsset(new Stock(assetName, price, quantity));  // Assuming Stock for simplicity
        }
        cout << "Portfolio loaded from " << filename << endl;
    } else {
        cerr << "Error loading portfolio from " << filename << endl;
    }
}

/**
 * @brief Saves the transaction log to a file.
 * 
 * Opens the file for writing. If successful, calls the displayLog method to
 * write the transaction log to the file.
 * 
 * @param log The TransactionLog object containing the transaction history.
 * @param filename The file where the transaction log will be saved.
 */
void FileManager::saveTransactionLog(const TransactionLog& log, const string& filename) {
    ofstream file(filename);
    
    // Check if the file is successfully opened
    if (file) {
        log.displayLog(file);  // Save the transaction log
        cout << "Transaction log saved to " << filename << endl;
    } else {
        cerr << "Error saving transaction log to " << filename << endl;
    }
}

/**
 * @brief Loads the transaction log from a file.
 * 
 * Opens the file for reading. If successful, reads each line of the transaction log
 * from the file and displays it to the console.
 * 
 * @param log The TransactionLog object to load the data into.
 * @param filename The file from which the transaction log will be loaded.
 */
void FileManager::loadTransactionLog(TransactionLog& log, const string& filename) {
    ifstream file(filename);
    
    // Check if the file is successfully opened
    if (file) {
        string line;
        
        // Read and display each line from the transaction log
        while (getline(file, line)) {
            cout << line << endl;
        }
        cout << "Transaction log loaded from " << filename << endl;
    } else {
        cerr << "Error loading transaction log from " << filename << endl;
    }
}

