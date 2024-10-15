#include "debug.h"

// Define and initialize the global debug mode variable
bool debugMode = false;  // Set to true to enable debug messages, false to disable

// Define the printDebug function
void printDebug(const std::string& message) {
    if (debugMode) {
        std::cout << "[DEBUG] " << message << std::endl;
    }
}