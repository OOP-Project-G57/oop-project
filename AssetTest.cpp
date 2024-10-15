#include <iostream>
#include "Stock.h"

using namespace std;

void test(bool condition, const string& testName) {
    if (condition) {
        cout << testName << " passed." << endl;
    } else {
        cout << testName << " failed!" << endl;
    }
}

int main() {
    //Test: Create a Stock object
    Stock stock("Apple", 150.0, 10);

    //Test 1: Check the initial value of the stock
    test(stock.getValue() == 1500.0, "Test 1: Initial Value Check");  // 150 * 10

    // Test 2: Test buying more stock
    stock.buy(5, 160.0);
    test(stock.getQuantity() == 15, "Test 2: Quantity after Buying");
    test(stock.getPrice() == 160.0, "Test 2: Price after Buying");
    test(stock.getValue() == 2400.0, "Test 2: Value after Buying");  // 160 * 15

    //Test 3: Test selling some stock
    stock.sell(8, 155.0);
    test(stock.getQuantity() == 7, "Test 3: Quantity after Selling");
    test(stock.getPrice() == 155.0, "Test 3: Price after Selling");
    test(stock.getValue() == 1085.0, "Test 3: Value after Selling");  // 155 * 7

    //Test 4: Display information (this will print to console)
    cout << "Displaying stock info:" << endl;
    stock.display();

    return 0;
}