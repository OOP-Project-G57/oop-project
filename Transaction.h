#pragma once
#include <iostream>
#include <string>

using namespace std;

// Transaction class declaration
class Transaction {
private:
    // Private member variables
    string assetName;
    string transactionType;
    int quantity;
    double price;
    string date;

public:
    // Constructor
    Transaction(string assetName, string type, int quantity, double price, string date);

    // Display transaction information
    void displayTransaction() const;
    void displayTransaction(ostream& out) const;
};