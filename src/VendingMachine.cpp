
#include <iostream>
#include "VendingMachine.h"

using namespace std;

/**
 * @brief Initializes products and sets the initial state to ReadyState.
 */
VendingMachine::VendingMachine()
    : water("Water", 500),
    juice("Juice", 1000),
    soda("Soda", 750),
    currentState(&readyState) {
}

/**
 * @brief Displays available products and their prices.
 */
void VendingMachine::displayProducts() const {
    cout << "========================\n";
    cout << "    Vending Machine\n";
    cout << "========================\n";

    cout << "1. " << water.getName() << " - " << water.getPrice() << " IQD\n";
    cout << "2. " << juice.getName() << " - " << juice.getPrice() << " IQD\n";
    cout << "3. " << soda.getName() << " - " << soda.getPrice() << " IQD\n";
}

/**
 * @brief Sends the purchase request to the current state.
 * @param choice Selected product number.
 * @param money Amount of money inserted in IQD.
 */
void VendingMachine::buyProduct(int choice, int money) {
    currentState->buy(*this, choice, money);
}

/**
 * @brief Returns the selected product.
 * @param choice Product number.
 * @return Pointer to the product or nullptr if invalid.
 */
Product* VendingMachine::getProduct(int choice) {
    if (choice == 1) return &water;
    if (choice == 2) return &juice;
    if (choice == 3) return &soda;

    return nullptr;
}

/**
 * @brief Changes the current state.
 * @param state New state.
 */
void VendingMachine::setState(State* state) {
    currentState = state;
}

/**
 * @brief Returns the current state.
 */
State* VendingMachine::getCurrentState() const {
    return currentState;
}

/**
 * @brief Returns the ready state.
 */
State* VendingMachine::getReadyState() {
    return &readyState;
}

/**
 * @brief Returns the dispensing state.
 */
State* VendingMachine::getDispensingState() {
    return &dispensingState;
}

/**
 * @brief Displays purchase confirmation and change.
 * @param product Purchased product.
 * @param money Amount of money inserted in IQD.
 */
void VendingMachine::dispenseProduct(const Product& product, int money) {
    cout << "\nPurchase successful!\n";
    cout << "Product: " << product.getName() << "\n";
    cout << "Change: " << money - product.getPrice() << " IQD\n";
}
