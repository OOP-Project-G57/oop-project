#include "Bond.h"
#include <cassert>
#include <iostream>

void testBond() {
    Bond govBond("Gov Bond", 1000, 5, 3.5);

    // Test buy function
    govBond.buy(3, 1050);
    assert(govBond.getQuantity() == 8);
    assert(govBond.getPrice() == 1050);

    // Test sell function
    bool sellSuccess = govBond.sell(2, 1030);
    assert(sellSuccess);
    assert(govBond.getQuantity() == 6);

    std::cout << "Bond tests passed!\n";
}

int main() {
    testBond();
    return 0;
}
