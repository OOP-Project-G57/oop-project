#include "Bond.h"  // Include the Bond class header

// Constructor: Initializes the Bond object with name, price, quantity, and interest rate.
// Calls the base class (Asset) constructor to set common attributes.
Bond::Bond(std::string n, double p, int q, double ir) 
    : Asset(n, p, q), interestRate(ir) {}

// Implementation of the buy function: 
// Increases the quantity by the specified amount and updates the price.
void Bond::buy(int q, double p) {
    quantity += q;  // Add to the existing quantity.
    price = p;  // Update the bond's price.
}

// Implementation of the sell function:
// Decreases the quantity if there is enough stock available and updates the price.
bool Bond::sell(int quantity, double price) {
    if (this->quantity >= quantity) {  // Check if enough quantity is available.
        this->quantity -= quantity;  // Subtract the sold quantity.
        this->price = price;  // Update the bond's price.
        return true;  // Return true if the sale is successful.
    } else {
        return false;  // Return false if there is not enough quantity to sell.
    }
}

// Overloaded << operator: 
// Allows printing the bond's details directly using an output stream (like std::cout).
std::ostream& operator<<(std::ostream& os, const Bond& bond) {
    os << bond.name << " - Price: " << bond.price 
       << ", Quantity: " << bond.quantity 
       << ", Interest Rate: " << bond.interestRate << "%";
    return os;  // Return the output stream to allow chaining of << operations.
}
