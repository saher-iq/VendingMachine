
#ifndef STATE_H
#define STATE_H

class VendingMachine;

/**
 * @brief Base class for vending machine states.
 */
class State {
public:
    virtual ~State() = default;

    /**
     * @brief Handles a purchase request.
     * @param machine Reference to the vending machine.
     * @param choice Selected product number.
     * @param money Amount of money inserted in IQD.
     */
    virtual void buy(VendingMachine& machine, int choice, int money) = 0;
};

/**
 * @brief Represents the ready state of the vending machine.
 */
class ReadyState : public State {
public:
    void buy(VendingMachine& machine, int choice, int money) override;
};

/**
 * @brief Represents the dispensing state of the vending machine.
 */
class DispensingState : public State {
public:
    void buy(VendingMachine& machine, int choice, int money) override;
};

#endif
