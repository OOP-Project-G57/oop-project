#include "User.h"
#include "Stock.h"
#include "Bond.h"
#include "Cryptocurrency.h"
#include <iostream>

void login() {
    int choice;
    std::string username, password;

    std::cout << "Welcome to the Financial Portfolio Management System!\n";
    std::cout << "1. Login\n2. Register\nPlease choose: ";
    std::cin >> choice;

    if (choice == 1) {
        // User login
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;

        // Authenticate user
        if (!User::loadUser(username, password)) {
            std::cout << "Exiting program due to failed login.\n";
            exit(1);  // Exit if login fails
        }
    } else if (choice == 2) {
        // Register a new user
        std::cout << "Register a new account.\n";
        std::cout << "Enter new username: ";
        std::cin >> username;
        std::cout << "Enter new password: ";
        std::cin >> password;

        // Save new user credentials
        User::registerUser(username, password);
    } else {
        std::cout << "Invalid choice. Exiting program.\n";
        exit(1);
    }
}

void testAssetSubclasses() {
    Stock appleStock("AAPL", 150.0, 10); // 10 shares of Apple stock at $150
    Bond treasuryBond("US Treasury", 1000.0, 5, 0.05); // 5 US Treasury bonds at $1000 with 5% interest
    Cryptocurrency bitcoin("Bitcoin", 50000.0, 2); // 2 Bitcoins at $50,000 each

    // Test Stock methods
    std::cout << "Testing Stock (Apple)..." << std::endl;
    std::cout << "Initial Value: $" << appleStock.getValue() << std::endl;
    appleStock.buy(5, 160.0); // Buy 5 more shares at $160
    std::cout << "Value after buying 5 shares at $160: $" << appleStock.getValue() << std::endl;
    appleStock.sell(3, 170.0); // Sell 3 shares at $170
    std::cout << "Value after selling 3 shares at $170: $" << appleStock.getValue() << std::endl;
    std::cout << "Profit/Loss: $" << appleStock.calculateProfitLoss() << std::endl;

    // Test Bond methods
    std::cout << "\nTesting Bond (US Treasury)..." << std::endl;
    std::cout << "Initial Value: $" << treasuryBond.getValue() << std::endl;
    treasuryBond.buy(2, 1020.0); // Buy 2 more bonds at $1020
    std::cout << "Value after buying 2 bonds at $1020: $" << treasuryBond.getValue() << std::endl;
    treasuryBond.sell(1, 1010.0); // Sell 1 bond at $1010
    std::cout << "Value after selling 1 bond at $1010: $" << treasuryBond.getValue() << std::endl;
    std::cout << "Profit/Loss: $" << treasuryBond.calculateProfitLoss() << std::endl;

    // Test Cryptocurrency methods
    std::cout << "\nTesting Cryptocurrency (Bitcoin)..." << std::endl;
    std::cout << "Initial Value: $" << bitcoin.getValue() << std::endl;
    bitcoin.buy(1, 52000.0); // Buy 1 more Bitcoin at $52,000
    std::cout << "Value after buying 1 Bitcoin at $52,000: $" << bitcoin.getValue() << std::endl;
    bitcoin.sell(2, 53000.0); // Sell 2 Bitcoins at $53,000
    std::cout << "Value after selling 2 Bitcoins at $53,000: $" << bitcoin.getValue() << std::endl;
    std::cout << "Profit/Loss: $" << bitcoin.calculateProfitLoss() << std::endl;
}

int main() {
    // User login or registration
    login();

    // Test the Asset subclasses
    testAssetSubclasses();

    return 0;
}
