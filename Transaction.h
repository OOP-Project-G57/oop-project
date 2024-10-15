#pragma once
#include <iostream>
#include <string>

/**
 * @brief Represents a transaction of an asset (buy or sell).
 */
class Transaction {
private:
    std::string assetName;
    std::string transactionType; // "buy" or "sell"
    int quantity;
    double price;
    std::string date;  // Date of transaction (e.g., "2024-09-25")

public:
    /**
    * @brief Constructor
    */
    Transaction(std::string assetName, std::string type, int quantity, double price, std::string date);

    /**
    * @brief Display transaction information
    */
    void displayTransaction() const;
    void displayTransaction(std::ostream& out) const;

    /**
    * @brief Getters for the transaction details
    */
    std::string getAssetName() const;
    std::string getTransactionType() const;
    int getQuantity() const;
    double getPrice() const;
    std::string getDate() const;
};