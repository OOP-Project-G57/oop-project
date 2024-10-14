#include <iostream>
#include "User.cpp"
#include "Asset.cpp"
#include "PortfolioManager.cpp"
#include "Transaction.cpp"
#include "FileManager.cpp"

using namespace std;

// Function prototypes for menu system
void displayMenu();
void addAsset(PortfolioManager& manager);
void buySellAsset(PortfolioManager& manager, TransactionLog& log);
void saveData(PortfolioManager& manager, TransactionLog& log, FileManager& fileManager, const std::string& username);
void loadData(PortfolioManager& manager, TransactionLog& log, FileManager& fileManager, const std::string& username);
void viewPortfolio(PortfolioManager& manager);
void viewTransactionLog(TransactionLog& log);

int main() {
    User user;
    string username, password;
    char choice;

    // User login or registration
    cout << "Welcome to the Financial Portfolio Management System\n";
    cout << "Do you have an account? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        // Login
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        user = User(username, password);
        if (!user.loadUser()) {
            cout << "Exiting the system...\n";
            return 0;
        }
    } else {
        // Register
        cout << "Register a new account\n";
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        user = User(username, password);
        user.registerUser();
    }

    // User is now logged in
    PortfolioManager manager;
    TransactionLog log;
    FileManager fileManager;

    // Load user's portfolio and transaction log if they exist
    loadData(manager, log, fileManager, username);

    // Main menu-driven system
    int menuChoice;
    do {
        displayMenu();
        cin >> menuChoice;

        switch (menuChoice) {
            case 1:
                addAsset(manager);
                break;
            case 2:
                buySellAsset(manager, log);
                break;
            case 3:
                viewPortfolio(manager);
                break;
            case 4:
                manager.displayPortfolioGraph();  // Call the graphical representation method
                break;
            case 5:
                viewTransactionLog(log);
                break;
            case 6:
                saveData(manager, log, fileManager, username);
                break;
            case 7:
                loadData(manager, log, fileManager, username);
                break;
            case 0:
                cout << "Exiting program and saving user data.\n";
                saveData(manager, log, fileManager, username);
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (menuChoice != 0);

    return 0;
}

// Function to display the menu options
void displayMenu() {
    cout << "\n--- Portfolio Manager Menu ---\n";
    cout << "1. Add an asset\n";
    cout << "2. Buy/Sell an asset\n";
    cout << "3. View portfolio\n";
    cout << "4. View portfolio graph\n";
    cout << "5. View transaction log\n";
    cout << "6. Save portfolio and transaction log\n";
    cout << "7. Load portfolio and transaction log\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

// Function to add an asset to the portfolio
void addAsset(PortfolioManager& manager) {
    string assetName;
    double price;
    int quantity;
    int assetType;

    cout << "Select asset type to add:\n";
    cout << "1. Stock\n";
    cout << "2. Bond\n";
    cout << "3. Cryptocurrency\n";
    cout << "4. Government Bond\n";
    cout << "Enter your choice: ";
    cin >> assetType;

    cout << "Enter asset name: ";
    cin >> assetName;
    cout << "Enter price: ";
    cin >> price;
    cout << "Enter quantity: ";
    cin >> quantity;

    switch (assetType) {
        case 1:
            manager.addAsset(new Stock(assetName, price, quantity));
            break;
        case 2:
            double interestRate;
            cout << "Enter interest rate (in %): ";
            cin >> interestRate;
            manager.addAsset(new Bond(assetName, price, quantity, interestRate));
            break;
        case 3:
            manager.addAsset(new Cryptocurrency(assetName, price, quantity));
            break;
        case 4:
            double maturity;
            cout << "Enter maturity period (in years): ";
            cin >> maturity;
            manager.addAsset(new GovernmentBond(assetName, price, quantity, maturity));
            break;
        default:
            cout << "Invalid asset type selected." << endl;
            return;
    }

    cout << "Asset added successfully.\n";
}

// Function to buy or sell an asset
void buySellAsset(PortfolioManager& manager, TransactionLog& log) {
    string assetName, type, date;
    int quantity;
    double price;

    cout << "Enter transaction type (buy/sell): ";
    cin >> type;
    cout << "Enter asset name: ";
    cin >> assetName;
    cout << "Enter quantity: ";
    cin >> quantity;
    cout << "Enter price: ";
    cin >> price;
    cout << "Enter date (YYYY-MM-DD): ";
    cin >> date;

    if (type == "buy") {
        manager.buyAsset(assetName, quantity, price);
        log.logTransaction(Transaction(assetName, "buy", quantity, price, date));
    } else if (type == "sell") {
        manager.sellAsset(assetName, quantity, price);
        log.logTransaction(Transaction(assetName, "sell", quantity, price, date));
    } else {
        cout << "Invalid transaction type." << endl;
    }
}

// Function to view the portfolio
void viewPortfolio(PortfolioManager& manager) {
    manager.displayPortfolio();
}

// Function to view the transaction log
void viewTransactionLog(TransactionLog& log) {
    log.displayLog();
}

// Function to save portfolio and transaction log
void saveData(PortfolioManager& manager, TransactionLog& log, FileManager& fileManager, const std::string& username) {
    string portfolioFile = username + "_portfolio.txt";
    string transactionFile = username + "_transactions.txt";

    fileManager.savePortfolio(manager, portfolioFile);
    fileManager.saveTransactionLog(log, transactionFile);
    cout << "Data saved successfully.\n";
}

// Function to load portfolio and transaction log
void loadData(PortfolioManager& manager, TransactionLog& log, FileManager& fileManager, const std::string& username) {
    string portfolioFile = username + "_portfolio.txt";
    string transactionFile = username + "_transactions.txt";

    fileManager.loadPortfolio(manager, portfolioFile);
    fileManager.loadTransactionLog(log, transactionFile);
    cout << "Data loaded successfully.\n";
}

