#pragma once

#include <iostream>
#include <string>

using namespace std;

class Asset {
protected:
    string name;
    double price;
    int quantity;
    double purchasePrice;

public:
    Asset(string name, double price, int quantity);
    virtual void buy(int q, double p) = 0;
    virtual void sell(int q, double p) = 0;
    virtual double getValue() const;

    void display() const;
    void display(ostream& out) const;

    string getName();
    int getQuantity();

    virtual double calculateProfitLoss() const;

    double getPrice() const;

    virtual ~Asset();
};