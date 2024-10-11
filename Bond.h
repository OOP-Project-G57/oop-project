#ifndef BOND_H
#define BOND_H

#include "Asset.h"

class Bond : public Asset {
protected:
    double interestRate;

public:
    Bond(std::string n, double p, int q, double ir);
    void buy(int q, double p) override;
    bool sell(int quantity, double price) override;
    friend std::ostream& operator<<(std::ostream& os, const Bond& bond);
};

#endif
