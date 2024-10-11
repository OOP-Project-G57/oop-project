#include "GovernmentBond.h"
#include <cassert>
#include <iostream>

void testGovernmentBond() {
    GovernmentBond gbond("US Treasury", 1000, 10, 2.5);

    // Test buy function
    gbond.buy(5, 1020);
    assert(gbond.getQuantity() == 15);
    assert(gbond.getPrice() == 1020);

    // Test sell function
    bool sellSuccess = gbond.sell(3, 1015);
    assert(sellSuccess);
    assert(gbond.getQuantity() == 12);

    std::cout << "Government Bond tests passed!\n";
}

int main() {
    testGovernmentBond();
    return 0;
}
