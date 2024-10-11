#ifndef ASSET_H
#define ASSET_H

#include <string>
#include <iostream>

class Asset {
protected:
    std::string name;
    double price;
    int quantity;
    double purchasePrice;

public:
    Asset(std::string name, double price, int quantity);
    virtual void buy(int q, double p) = 0;
    virtual bool sell(int q, double p) = 0;
    virtual double getValue() const;
    void display() const;
    void display(std::ostream& out) const;
    std::string getName() const;
    int getQuantity() const;
    double getPrice() const;
    virtual ~Asset() {}
};

#endif
