#include "Stock.h"            // Include the Stock class
#include "Bond.h"             // Include the Bond class
#include "Cryptocurrency.h"   // Include the Cryptocurrency class
#include "GovernmentBond.h"   // Include the GovernmentBond class
#include "User.h"             // Include the User class
#include <iostream>           // For input/output operations (std::cin, std::cout)
#include <string>             // For using std::string

using namespace std;  // Use the standard namespace to avoid prefixing std::

// Function to handle user login or registration
void handleUserLogin() {
    int choice;  // Stores user's menu choice
    string username, password;  // Stores entered username and password

    // Display welcome message and login/registration options
    cout << "Welcome to the Portfolio Manager!\n";
    cout << "1. Register\n2. Login\nChoose an option (1 or 2): ";
    cin >> choice;  // Get the user's choice

    // Prompt user for credentials
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Create a User object with the entered credentials
    User user(username, password);

    // Handle registration or login based on the user's choice
    if (choice == 1) {
        user.registerUser();  // Register the user
    } else if (choice == 2) {
        if (!user.loadUser()) {  // Attempt login, exit if it fails
            cout << "Login failed. Exiting...\n";
            exit(0);  // Exit the program on login failure
        }
    } else {
        cout << "Invalid choice. Exiting...\n";
        exit(0);  // Exit the program on invalid choice
    }
}

// Main function to run the program
int main() {
    // Handle user login or registration
    handleUserLogin();

    // After successful login, create asset objects
    Stock apple("AAPL", 150, 10);  // Create a Stock object
    GovernmentBond govBond("Gov Bond", 1000, 5, 3.5);  // Create a GovernmentBond object
    Cryptocurrency bitcoin("Bitcoin", 30000, 2);  // Create a Cryptocurrency object

    // Display initial information for the assets
    apple.display();  // Display stock details
    govBond.display(cout);  // Display government bond details using std::cout
    bitcoin.display();  // Display cryptocurrency details

    return 0;  // Return 0 to indicate successful execution
}
