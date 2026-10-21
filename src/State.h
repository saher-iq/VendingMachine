
#ifndef STATE_H
#define STATE_H

class VendingMachine;

class State {
public:
    virtual ~State() = default;

    virtual void buy(
        VendingMachine& machine,
        int choice,
        int money
    ) = 0;
};

class ReadyState : public State {
public:
    void buy(
        VendingMachine& machine,
        int choice,
        int money
    ) override;
};

class DispensingState : public State {
public:
    void buy(
        VendingMachine& machine,
        int choice,
        int money
    ) override;
};

#endif
