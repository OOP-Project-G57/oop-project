#include "Transaction.h"

//Constructs a Transaction object.
Transaction::Transaction(std::string assetName, std::string type, int quantity, double price, std::string date)
    : assetName(assetName), transactionType(type), quantity(quantity), price(price), date(date) {}

//Display the transaction details to the console.
void Transaction::displayTransaction() const {
    displayTransaction(std::cout); // Calls the overloaded method with cout
}

//Display the transaction details to the specified output stream.
void Transaction::displayTransaction(std::ostream& out) const {
    // Simplified output formatting
    out << "Asset: " << assetName << ", Type: " << transactionType
        << ", Quantity: " << quantity << ", Price: " << price
        << ", Date: " << date << std::endl;
}

//Returns the asset name associated with the transaction.
std::string Transaction::getAssetName() const { return assetName; }

//Returns the type of transaction (buy or sell).
std::string Transaction::getTransactionType() const { return transactionType; }

//Returns the quantity of assets transacted.
int Transaction::getQuantity() const { return quantity; }

//Returns the price per asset for the transaction.
double Transaction::getPrice() const { return price; }

//Returns the date of the transaction.
std::string Transaction::getDate() const { return date; }
