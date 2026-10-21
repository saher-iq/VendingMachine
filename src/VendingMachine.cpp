
#include <iostream>
#include "VendingMachine.h"

using namespace std;

VendingMachine::VendingMachine()
    : water("Water", 500),
    juice("Juice", 1000),
    soda("Soda", 750),
    currentState(&readyState) {
}

void VendingMachine::displayProducts() const {
    cout << "========================\n";
    cout << "    Vending Machine\n";
    cout << "========================\n";

    cout << "1. " << water.getName()
        << " - " << water.getPrice() << " IQD\n";

    cout << "2. " << juice.getName()
        << " - " << juice.getPrice() << " IQD\n";

    cout << "3. " << soda.getName()
        << " - " << soda.getPrice() << " IQD\n";
}

void VendingMachine::buyProduct(int choice, int money) {
    currentState->buy(*this, choice, money);
}

Product* VendingMachine::getProduct(int choice) {
    if (choice == 1) return &water;
    if (choice == 2) return &juice;
    if (choice == 3) return &soda;

    return nullptr;
}

void VendingMachine::setState(State* state) {
    currentState = state;
}

State* VendingMachine::getReadyState() {
    return &readyState;
}

State* VendingMachine::getDispensingState() {
    return &dispensingState;
}

void VendingMachine::dispenseProduct(
    const Product& product,
    int money
) {
    cout << "\nPurchase successful!\n";
    cout << "Product: " << product.getName() << "\n";
    cout << "Change: "
        << money - product.getPrice()
        << " IQD\n";
}
