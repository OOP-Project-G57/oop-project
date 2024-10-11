#include "User.h"
#include <cassert>
#include <iostream>

void testUser() {
    User newUser("testuser", "password123");

    // Register the user
    newUser.registerUser();

    // Test login with correct credentials
    bool loginSuccess = newUser.loadUser();
    assert(loginSuccess);

    // Test login with incorrect credentials
    User wrongUser("testuser", "wrongpassword");
    bool wrongLogin = wrongUser.loadUser();
    assert(!wrongLogin);

    std::cout << "User tests passed!\n";
}

int main() {
    testUser();
    return 0;
}
