#include "Stock.h"
#include "Bond.h"
#include "Cryptocurrency.h"
#include "GovernmentBond.h"
#include "User.h"
#include <iostream>
#include <string>

using namespace std;

// Function to handle user login or registration
void handleUserLogin() {
    int choice;
    string username, password;
    
    cout << "Welcome to the Portfolio Manager!\n";
    cout << "1. Register\n2. Login\nChoose an option (1 or 2): ";
    cin >> choice;
    
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    
    User user(username, password);

    if (choice == 1) {
        user.registerUser();
    } else if (choice == 2) {
        if (!user.loadUser()) {
            cout << "Login failed. Exiting...\n";
            exit(0);  // Exit the program if login fails
        }
    } else {
        cout << "Invalid choice. Exiting...\n";
        exit(0);  // Exit the program for invalid choice
    }
}

int main() {
    // Handle login/registration
    handleUserLogin();

    // After login, user can access asset functionalities
    Stock apple("AAPL", 150, 10);
    GovernmentBond govBond("Gov Bond", 1000, 5, 3.5);
    Cryptocurrency bitcoin("Bitcoin", 30000, 2);

    // Display initial information
    apple.display();
    govBond.display(cout);
    bitcoin.display();

    return 0;
}
