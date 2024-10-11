#ifndef USER_H
#define USER_H

#include <string>

class User {
    std::string username;
    std::string password;

public:
    User();
    User(std::string u, std::string p);

    bool loadUser();  // Load user data
    void registerUser();  // Register a new user
    std::string getUsername() const;  // Getter for username
};

#endif
