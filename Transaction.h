#pragma once

#include <iostream>
#include <string>

using namespace std;

class Transaction {
private:
    string assetName;
    string transactionType;
    int quantity;
    double price;
    string date;

public:
    Transaction(string assetName, string type, int quantity, double price, string date);
    void displayTransaction() const;
    void displayTransaction(ostream& out) const;
};