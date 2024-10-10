#ifndef BOND_H
#define BOND_H

#include "Asset.h"

class Bond : public Asset {
protected:
    double interestRate;

public:
    Bond(std::string n, double p, int q, double ir)
        : Asset(n, p, q, p), interestRate(ir) {}

    double getValue() const override;
    void buy(int q, double price) override;
    void sell(int q, double price) override;
    double calculateProfitLoss() const override;
};

#endif
