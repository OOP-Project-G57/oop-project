#ifndef USER_H  // Prevent multiple inclusions of this header file
#define USER_H

#include <string>  // Include string for using std::string

// User class to represent a system user with username and password
class User {
    std::string username;  // Stores the user's username
    std::string password;  // Stores the user's password

public:
    // Default constructor
    User();

    // Parameterized constructor to initialize username and password
    User(std::string u, std::string p);

    // Loads user data from a file to authenticate the user
    bool loadUser();

    // Registers a new user by saving their credentials to a file
    void registerUser();

    // Getter function to return the username
    std::string getUsername() const;
};

#endif  // End of include guard
