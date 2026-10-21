
#include <iostream>
#include "State.h"
#include "VendingMachine.h"

using namespace std;

void ReadyState::buy(VendingMachine& machine, int choice, int money) {
    Product* product = machine.getProduct(choice);

    if (product == nullptr) {
        cout << "Invalid choice!\n";
        return;
    }

    if (money < 0) {
        cout << "Invalid amount!\n";
        return;
    }

    if (money < product->getPrice()) {
        cout << "Not enough money!\n";
        cout << "You need "
            << product->getPrice() - money
            << " IQD more.\n";
        return;
    }

    // Change to DispensingState before processing the purchase.
    machine.setState(machine.getDispensingState());

    // The purchase is now handled by DispensingState.
    machine.buyProduct(choice, money);
}

void DispensingState::buy(VendingMachine& machine, int choice, int money) {
    Product* product = machine.getProduct(choice);

    if (product == nullptr || money < product->getPrice()) {
        cout << "Cannot dispense product.\n";
        machine.setState(machine.getReadyState());
        return;
    }

    machine.dispenseProduct(*product, money);

    // Return to ReadyState after dispensing the product.
    machine.setState(machine.getReadyState());
}
