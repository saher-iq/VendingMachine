
#ifndef VENDING_MACHINE_H
#define VENDING_MACHINE_H

#include "Product.h"
#include "State.h"

/**
 * @brief Controls the vending machine operations.
 */
class VendingMachine {
private:
    Product water;
    Product juice;
    Product soda;

    ReadyState readyState;
    DispensingState dispensingState;
    State* currentState;

public:
    /**
     * @brief Initializes the vending machine and its products.
     */
    VendingMachine();

    /**
     * @brief Displays all available products and their prices.
     */
    void displayProducts() const;

    /**
     * @brief Processes a product purchase.
     * @param choice Selected product number.
     * @param money Amount of money inserted in IQD.
     */
    void buyProduct(int choice, int money);

    /**
     * @brief Dispenses the selected product and returns change.
     * @param product Selected product.
     * @param money Amount of money inserted in IQD.
     */
    void dispenseProduct(const Product& product, int money);

    /**
     * @brief Finds a product by its selection number.
     * @param choice Product number.
     * @return Pointer to the product, or nullptr if invalid.
     */
    Product* getProduct(int choice);

    /**
     * @brief Changes the current state.
     * @param state New state.
     */
    void setState(State* state);

    /**
     * @brief Returns the current state.
     * @return Pointer to the current state.
     */
    State* getCurrentState() const;

    /**
     * @brief Returns the ready state.
     * @return Pointer to ReadyState.
     */
    State* getReadyState();

    /**
     * @brief Returns the dispensing state.
     * @return Pointer to DispensingState.
     */
    State* getDispensingState();
};

#endif
