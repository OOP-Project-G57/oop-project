#include <iostream>
#include "User.cpp"
#include "Asset.cpp"
#include "PortfolioManager.cpp"
#include "Transaction.cpp"
#include "FileManager.cpp"
#include <chrono>
#include <thread>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

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


void slowPrint(const std::string& str, unsigned int millis_per_char) {
    for (const char c : str) {
        std::cout << c;
        std::this_thread::sleep_for(std::chrono::milliseconds(millis_per_char));
    }
}

void displayMenu() {
    unsigned int fastSpeed = 2; // Speed up the animation by reducing delay
    slowPrint(BLUE "╔══════════════════════════════╗\n", fastSpeed);
    slowPrint(CYAN "║       Portfolio Manager      ║\n", fastSpeed);
    slowPrint(BLUE "╠══════════════════════════════╣\n", fastSpeed);
    slowPrint(GREEN "║ 1. Add an Asset              ║\n", fastSpeed);
    slowPrint(GREEN "║ 2. Buy/Sell an Asset         ║\n", fastSpeed);
    slowPrint(GREEN "║ 3. View Portfolio            ║\n", fastSpeed);
    slowPrint(GREEN "║ 4. View Portfolio Graph      ║\n", fastSpeed);
    slowPrint(GREEN "║ 5. View Transaction Log      ║\n", fastSpeed);  // Added missing option
    slowPrint(GREEN "║ 6. Save Portfolio            ║\n", fastSpeed);
    slowPrint(GREEN "║ 7. Load Portfolio            ║\n", fastSpeed);
    slowPrint(RED "║ 0. Exit                      ║\n", fastSpeed);
    slowPrint(BLUE "╚══════════════════════════════╝\n", fastSpeed);
    std::cout << RESET;
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

// Function to display a progress bar
void showProgressBar(const std::string& task) {
    std::cout << task << " [" << std::flush;
    for (int i = 0; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));  // Adjust speed here if needed
        std::cout << "-" << std::flush;
    }
    std::cout << "] Done!" << std::endl;
}

// Function to save portfolio and transaction log
void saveData(PortfolioManager& manager, TransactionLog& log, FileManager& fileManager, const std::string& username) {
    std::string portfolioFile = username + "_portfolio.txt";
    std::string transactionFile = username + "_transactions.txt";

    showProgressBar("Saving Portfolio");  // Display progress bar for saving portfolio
    fileManager.savePortfolio(manager, portfolioFile);

    showProgressBar("Saving Transaction Log");  // Display progress bar for saving transaction log
    fileManager.saveTransactionLog(log, transactionFile);

    std::cout << "Data saved successfully." << std::endl;
}

// Function to load portfolio and transaction log
void loadData(PortfolioManager& manager, TransactionLog& log, FileManager& fileManager, const std::string& username) {
    std::string portfolioFile = username + "_portfolio.txt";
    std::string transactionFile = username + "_transactions.txt";

    showProgressBar("Loading Portfolio");  // Display progress bar for loading portfolio
    fileManager.loadPortfolio(manager, portfolioFile);

    showProgressBar("Loading Transaction Log");  // Display progress bar for loading transaction log
    fileManager.loadTransactionLog(log, transactionFile);

    std::cout << "Data loaded successfully." << std::endl;
}