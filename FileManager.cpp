#include "FileManager.h"

// Save the portfolio to a file
void FileManager::savePortfolio(const PortfolioManager& manager, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << "Portfolio Assets:" << endl;
        manager.displayPortfolio(file);  // Use file stream instead of cout
        file.close();
        cout << "Portfolio saved to " << filename << endl;
    } else {
        cout << "Error opening file for saving portfolio!" << endl;
    }
}

// Load the portfolio from a file (this will just simulate the load functionality)
void FileManager::loadPortfolio(PortfolioManager& manager, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        cout << "Loading portfolio from " << filename << endl;
        // In reality, you would parse the file and load the assets into PortfolioManager
        // For now, we're simulating loading
        string line;
        while (getline(file, line)) {
            cout << line << endl;  // Display the file contents to simulate load
        }
        file.close();
    } else {
        cout << "Error opening file for loading portfolio!" << endl;
    }
}

// Save the transaction log to a file
void FileManager::saveTransactionLog(const TransactionLog& log, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        log.displayLog(file);  // Log transactions to file stream
        file.close();
        cout << "Transaction log saved to " << filename << endl;
    } else {
        cout << "Error opening file for saving transaction log!" << endl;
    }
}

// Load the transaction log from a file (just simulating loading)
void FileManager::loadTransactionLog(TransactionLog& log, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        cout << "Loading transaction log from " << filename << endl;
        // Simulate loading the transaction log
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Error opening file for loading transaction log!" << endl;
    }
}
