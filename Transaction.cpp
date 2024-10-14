#include "Transaction.h"

Transaction::Transaction(string assetName, string type, int quantity, double price, string date)
    : assetName(assetName), transactionType(type), quantity(quantity), price(price), date(date) {}

void Transaction::displayTransaction() const {
    displayTransaction(cout);
}

void Transaction::displayTransaction(ostream& out) const {
    out << "Transaction - Asset: " << assetName
        << ", Type: " << transactionType
        << ", Quantity: " << quantity
        << ", Price: " << price
        << ", Date: " << date << endl;
}