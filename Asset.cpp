/**
 * @brief Include the Asset class header
 */
#include "Asset.h"  

/**
 * @brief Constructor to initialize the asset with name, price, and quantity
 */
Asset::Asset(std::string name, double price, int quantity) 
    : name(name), price(price), quantity(quantity), purchasePrice(price) {}

/**
 * @brief Calculates and returns the total value of the asset (price * quantity)
 */
double Asset::getValue() const {
    return price * quantity;
}

/**
 * @brief Displays the asset details to the console by calling the overloaded display function
 */

void Asset::display() const {
    display(std::cout);  // Pass std::cout as the default output stream
}

/**
 * @brief Overloaded display function that prints asset details to a given output stream
 */
void Asset::display(std::ostream& out) const {
    out << name << " - Price: " << price 
        << ", Quantity: " << quantity 
        << ", Value: " << getValue() << std::endl;
}

/**
 * @brief Returns the name of the asset
 */
std::string Asset::getName() const {
    return name;
}

/**
 * @brief Returns the quantity of the asset held
 */
int Asset::getQuantity() const {
    return quantity;
}

/**
 * @brief Returns the current price of the asset
 */
double Asset::getPrice() const {
    return price;
}

/**
 * @brief Profit or loss is calculated as (current value - original value)
 */
double Asset::calculateProfitLoss() const {
    return (quantity * price) - (quantity * purchasePrice);
}