#include "User.h"

bool User::loadUser(const std::string& u, const std::string& p) {
    std::ifstream file("users.txt");
    std::string storedUser, storedPass;
    while (file >> storedUser >> storedPass) {
        if (storedUser == u && storedPass == p) {
            std::cout << "Login successful! Welcome " << u << "!\n";
            return true;
        }
    }
    std::cout << "Invalid username or password.\n";
    return false;
}

void User::registerUser(const std::string& u, const std::string& p) {
    std::ofstream file("users.txt", std::ios::app);
    file << u << " " << p << "\n";
    std::cout << "User " << u << " registered successfully!\n";
}
