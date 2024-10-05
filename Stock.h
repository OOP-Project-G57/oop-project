#ifndef STOCK_H
#define STOCK_H

#include "Asset.h"

class Stock : public Asset {
public:
    Stock(std::string n, double p, int q) : Asset(n, p, q, p) {}

    double getValue() const override;
    void buy(int q, double price) override;
    void sell(int q, double price) override;
    double calculateProfitLoss() const override;
};

#endif
