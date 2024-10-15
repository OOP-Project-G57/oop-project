#include "User.h"      // Include the User class header
#include <cassert>      // For using assertions to validate test results
#include <iostream>     // For input/output operations (std::cout)

// Function to test the User class functionality
void testUser() {
    // Create a new User with valid credentials
    User newUser("testuser", "password123");

    // Register the user by writing credentials to the "users.txt" file
    newUser.registerUser();

    // Test: Attempt login with the correct credentials
    bool loginSuccess = newUser.loadUser();  // Should return true
    assert(loginSuccess);  // Ensure the login succeeds (assertion fails if not true)

    // Test: Attempt login with incorrect credentials
    User wrongUser("testuser", "wrongpassword");  // User with incorrect password
    bool wrongLogin = wrongUser.loadUser();  // Should return false
    assert(!wrongLogin);  // Ensure the login fails (assertion fails if not false)

    // If all tests pass, print a success message
    std::cout << "User tests passed!\n";
}

// Main function to run the testUser function
int main() {
    testUser();  // Call the test function
    return 0;    // Return 0 to indicate successful execution
}
