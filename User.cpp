#include "User.h"      // Include the User class header
#include <fstream>      // For file operations (ifstream, ofstream)
#include <iostream>     // For input/output operations (std::cout)

// Default constructor: Initializes an empty User object
User::User() {}

// Parameterized constructor: Initializes the User with a username and password
User::User(std::string u, std::string p) 
    : username(u), password(p) {}

// Method to load user data from a file for login
// Checks if the entered username and password match any stored in "users.txt"
bool User::loadUser() {
    std::ifstream file("users.txt");  // Open the users file for reading
    std::string storedUser, storedPass;  // Variables to hold stored credentials

    // Read username-password pairs from the file
    while (file >> storedUser >> storedPass) {
        // Check if the entered credentials match
        if (storedUser == username && storedPass == password) {
            std::cout << "Login successful! Welcome " << username << "!\n";
            return true;  // Login successful
        }
    }

    // If no match is found, print an error message
    std::cout << "Invalid username or password.\n";
    return false;  // Login failed
}

// Method to register a new user by appending to "users.txt"
void User::registerUser() {
    std::ofstream file("users.txt", std::ios::app);  // Open file in append mode
    file << username << " " << password << "\n";  // Write credentials to the file
    std::cout << "User " << username << " registered successfully!\n";
}

// Getter function to return the username
std::string User::getUsername() const {
    return username;
}
