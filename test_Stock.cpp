#include "Stock.h"
#include <cassert>
#include <iostream>

void testStock() {
    Stock apple("AAPL", 150, 10);

    // Test buy function
    apple.buy(5, 200);
    assert(apple.getQuantity() == 15);
    assert(apple.getPrice() == 200);

    // Test sell function
    bool sellSuccess = apple.sell(5, 180);
    assert(sellSuccess);
    assert(apple.getQuantity() == 10);

    std::cout << "Stock tests passed!\n";
}

int main() {
    testStock();
    return 0;
}
