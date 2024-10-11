#include "Cryptocurrency.h"
#include <cassert>
#include <iostream>

void testCryptocurrency() {
    Cryptocurrency bitcoin("Bitcoin", 30000, 2);

    // Test buy function
    bitcoin.buy(1, 35000);
    assert(bitcoin.getQuantity() == 3);
    assert(bitcoin.getPrice() == 35000);

    // Test sell function
    bool sellSuccess = bitcoin.sell(1, 34000);
    assert(sellSuccess);
    assert(bitcoin.getQuantity() == 2);

    std::cout << "Cryptocurrency tests passed!\n";
}

int main() {
    testCryptocurrency();
    return 0;
}
