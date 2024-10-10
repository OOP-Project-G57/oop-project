#ifndef USER_H
#define USER_H

#include <string>
#include <fstream>
#include <iostream>

class User {
    std::string username;
    std::string password;

public:
    User() {}
    User(std::string u, std::string p) : username(u), password(p) {}

    static bool loadUser(const std::string& u, const std::string& p);
    static void registerUser(const std::string& u, const std::string& p);
};

#endif
