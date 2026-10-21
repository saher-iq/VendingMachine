
#include <iostream>
#include "VendingMachine.h"

using namespace std;

int main() {
    VendingMachine machine;

    machine.displayProducts();

    int choice;
    int money;

    cout << "\nChoose a product (1-3): ";
    cin >> choice;

    cout << "Enter money (IQD): ";
    cin >> money;

    machine.buyProduct(choice, money);

    return 0;
}
