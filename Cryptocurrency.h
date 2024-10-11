#ifndef CRYPTOCURRENCY_H
#define CRYPTOCURRENCY_H

#include "Asset.h"

class Cryptocurrency : public Asset {
public:
    Cryptocurrency(std::string n, double p, int q);
    void buy(int q, double p) override;
    bool sell(int quantity, double price) override;
};

#endif
