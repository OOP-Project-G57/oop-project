#ifndef ASSET_H
#define ASSET_H

#include <string>

class Asset {
protected:
    std::string name;
    double price;
    int quantity;
    double purchasePrice;

public:
    Asset(std::string n, double p, int q, double pp)
        : name(n), price(p), quantity(q), purchasePrice(pp) {}

    virtual ~Asset() {}

    virtual double getValue() const = 0; // Pure virtual function
    virtual void buy(int q, double price) = 0; // Pure virtual function
    virtual void sell(int q, double price) = 0; // Pure virtual function
    virtual double calculateProfitLoss() const = 0; // Pure virtual function

    std::string getName() const { return name; }
    int getQuantity() const { return quantity; }
};

#endif
