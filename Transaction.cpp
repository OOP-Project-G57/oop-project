#include "Transaction.h"

// Transaction class constructor
Transaction::Transaction(string assetName, string type, int quantity, double price, string date)
    : assetName(assetName), transactionType(type), quantity(quantity), price(price), date(date) {
    // Initialize transaction properties with provided values.
}

// Display transaction information to the console
void Transaction::displayTransaction() const {
    // Call the overloaded displayTransaction method with standard output stream
    displayTransaction(cout);
}

// Display transaction information to a specified output stream
void Transaction::displayTransaction(ostream& out) const {
    // Output transaction details in a formatted manner
    out << "Transaction - Asset: " << assetName
        << ", Type: " << transactionType
        << ", Quantity: " << quantity
        << ", Price: " << price
        << ", Date: " << date << endl;
}