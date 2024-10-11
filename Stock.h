#ifndef STOCK_H
#define STOCK_H

#include "Asset.h"

class Stock : public Asset {
public:
    Stock(std::string n, double p, int q);
    void buy(int q, double p) override;
    bool sell(int quantity, double price) override;
};

#endif
