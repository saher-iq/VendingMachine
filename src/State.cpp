
#include <iostream>
#include "State.h"
#include "VendingMachine.h"

using namespace std;

/**
 * @brief Handles purchase requests while the machine is ready.
 */
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
        cout << "You need " << product->getPrice() - money << " IQD more.\n";
        return;
    }

    machine.setState(machine.getDispensingState());
    machine.buyProduct(choice, money);
}

/**
 * @brief Handles product dispensing and returns the machine to ready state.
 */
void DispensingState::buy(VendingMachine& machine, int choice, int money) {
    Product* product = machine.getProduct(choice);

    if (product == nullptr || money < product->getPrice()) {
        cout << "Cannot dispense product.\n";
        machine.setState(machine.getReadyState());
        return;
    }

    machine.dispenseProduct(*product, money);
    machine.setState(machine.getReadyState());
}
