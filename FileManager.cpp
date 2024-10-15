#include "FileManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "PortfolioManager.h"
#include "Transaction.h"
#include "debug.h"

using namespace std;

// Saves the portfolio to the specified file
void FileManager::savePortfolio(const PortfolioManager& manager, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& pair : manager.getPortfolio()) {
            const Asset* asset = pair.second;
            // Write each asset's details to the file
            file << asset->getName() << " " << asset->getPrice() << " " << asset->getQuantity() << endl;
        }
        file.close();
        cout << "Portfolio saved to " << filename << endl;
    } else {
        cout << "Error opening file for saving portfolio!" << endl;
    }
}

// Loads the portfolio from the specified file
void FileManager::loadPortfolio(PortfolioManager& manager, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        cout << "Loading portfolio from " << filename << endl;

        string assetName;
        double price;
        int quantity;

        // Clear existing portfolio before loading new data
        manager.clearPortfolio();

        // Read the asset details and add them to the PortfolioManager
        while (file >> assetName >> price >> quantity) {
            printDebug("Read from file - Asset: " + assetName + ", Price: " + to_string(price) + ", Quantity: " + to_string(quantity));
            manager.addAsset(new Stock(assetName, price, quantity));
        }

        file.close();
        cout << "Portfolio loaded successfully.\n";
        printDebug("Portfolio size after loading: " + to_string(manager.getPortfolioSize()));
    } else {
        cout << "Error opening file for loading portfolio!\n";
    }
}

// Loads the transaction log from the specified file
void FileManager::loadTransactionLog(TransactionLog& log, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        cout << "Loading transaction log from " << filename << endl;

        string line, assetName, type, date;
        int quantity;
        double price;

        log.clear();  // Clear the log before loading new data

        // Skip the first two lines (headers)
        getline(file, line);
        getline(file, line);

        // Read transaction details from the file and add them to the TransactionLog
        while (file >> assetName >> type >> quantity >> price >> date) {
            log.logTransaction(Transaction(assetName, type, quantity, price, date));
        }

        file.close();
    } else {
        cout << "Error opening file for loading transaction log!" << endl;
    }
}

// Saves the transaction log to the specified file
void FileManager::saveTransactionLog(const TransactionLog& log, const string& filename) {
    ofstream file(filename, ios::trunc);  // Open file in trunc mode to overwrite existing content
    if (file.is_open()) {
        log.displayLog(file, false);  // Save log without color formatting
        file.close();
        cout << "Transaction log saved to " << filename << endl;
    } else {
        cout << "Error opening file for saving transaction log!" << endl;
    }
}
