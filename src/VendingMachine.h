
#ifndef VENDING_MACHINE_H
#define VENDING_MACHINE_H

#include "Product.h"
#include "State.h"

class VendingMachine {
private:
    Product water;
    Product juice;
    Product soda;

    ReadyState readyState;
    DispensingState dispensingState;
    State* currentState;

public:
    VendingMachine();

    void displayProducts() const;
    void buyProduct(int choice, int money);

    Product* getProduct(int choice);
    void setState(State* state);
    State* getCurrentState() const;

    State* getReadyState();
    State* getDispensingState();




    void dispenseProduct(const Product& product, int money);
};

#endif
