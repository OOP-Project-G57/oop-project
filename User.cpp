#include "User.h"
#include <fstream>
#include <iostream>

// Default constructor
User::User() {}

// Parameterized constructor
User::User(std::string u, std::string p) : username(u), password(p) {}

// Method to load the user from a file (login)
bool User::loadUser() {
    std::ifstream file("users.txt");
    std::string storedUser, storedPass;
    while (file >> storedUser >> storedPass) {
        if (storedUser == username && storedPass == password) {
            std::cout << "Login successful! Welcome " << username << "!\n";
            return true;
        }
    }
    std::cout << "Invalid username or password.\n";
    return false;
}

// Method to register a new user by writing to a file
void User::registerUser() {
    std::ofstream file("users.txt", std::ios::app);
    file << username << " " << password << "\n";
    std::cout << "User " << username << " registered successfully!\n";
}

// Getter for username
std::string User::getUsername() const {
    return username;
}
