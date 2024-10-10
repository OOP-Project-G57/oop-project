#ifndef CRYPTOCURRENCY_H
#define CRYPTOCURRENCY_H

#include "Asset.h"

class Cryptocurrency : public Asset {
public:
    Cryptocurrency(std::string n, double p, int q) : Asset(n, p, q, p) {}

    double getValue() const override;
    void buy(int q, double price) override;
    void sell(int q, double price) override;
    double calculateProfitLoss() const override;
};

#endif
