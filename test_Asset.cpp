#include "Asset.h"
#include "Stock.h"
#include <cassert>
#include <iostream>

void testAsset() {
    Stock apple("AAPL", 150, 10);
    assert(apple.getName() == "AAPL");
    assert(apple.getPrice() == 150);
    assert(apple.getQuantity() == 10);

    std::cout << "Asset (via Stock) tests passed!\n";
}

int main() {
    testAsset();
    return 0;
}
