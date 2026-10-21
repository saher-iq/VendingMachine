
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include <string>

#include "Product.h"
#include "VendingMachine.h"

// Helper function to capture console output.
std::string captureOutput(VendingMachine& machine, int choice, int money) {
    std::ostringstream output;
    std::streambuf* oldOutput = std::cout.rdbuf(output.rdbuf());

    try {
        machine.buyProduct(choice, money);
    }
    catch (...) {
        std::cout.rdbuf(oldOutput);
        throw;
    }

    std::cout.rdbuf(oldOutput);
    return output.str();
}

// Test 1: Check product name and price.
TEST(ProductTests, WaterHasCorrectNameAndPrice) {
    Product water("Water", 500);

    EXPECT_EQ(water.getName(), "Water");
    EXPECT_EQ(water.getPrice(), 500);
}

// Test 2: Check that valid products can be selected.
TEST(VendingMachineTests, ValidProductCanBeSelected) {
    VendingMachine machine;

    EXPECT_NE(machine.getProduct(1), nullptr);
    EXPECT_NE(machine.getProduct(2), nullptr);
    EXPECT_NE(machine.getProduct(3), nullptr);
}

// Test 3: Invalid product choices should return nullptr.
TEST(VendingMachineTests, InvalidProductReturnsNullptr) {
    VendingMachine machine;

    EXPECT_EQ(machine.getProduct(0), nullptr);
    EXPECT_EQ(machine.getProduct(4), nullptr);
}

// Test 4: Insufficient money should show an error.
TEST(VendingMachineTests, InsufficientMoneyShowsMessage) {
    VendingMachine machine;

    std::string output = captureOutput(machine, 1, 200);

    EXPECT_NE(output.find("Not enough money!"), std::string::npos);
    EXPECT_NE(output.find("300 IQD more"), std::string::npos);
}

// Test 5: A purchase with exact money should succeed.
TEST(VendingMachineTests, SufficientMoneyCompletesPurchase) {
    VendingMachine machine;

    std::string output = captureOutput(machine, 1, 500);

    EXPECT_NE(output.find("Purchase successful!"), std::string::npos);
    EXPECT_NE(output.find("Change: 0 IQD"), std::string::npos);
}

// Test 6: An invalid product choice should show an error.
TEST(VendingMachineTests, InvalidChoiceShowsMessage) {
    VendingMachine machine;

    std::string output = captureOutput(machine, 4, 1000);

    EXPECT_NE(output.find("Invalid choice!"), std::string::npos);
}

// Test 7: Negative money should be rejected.
TEST(VendingMachineTests, NegativeMoneyShowsMessage) {
    VendingMachine machine;

    std::string output = captureOutput(machine, 1, -100);

    EXPECT_NE(output.find("Invalid amount!"), std::string::npos);
}

// Test 8: Extra money should produce the correct change.
TEST(VendingMachineTests, ExtraMoneyReturnsCorrectChange) {
    VendingMachine machine;

    std::string output = captureOutput(machine, 1, 700);

    EXPECT_NE(output.find("Purchase successful!"), std::string::npos);
    EXPECT_NE(output.find("Change: 200 IQD"), std::string::npos);
}

// Test 9: The machine should return to ReadyState after a purchase.
TEST(VendingMachineTests, MachineReturnsToReadyStateAfterPurchase) {
    VendingMachine machine;

    EXPECT_EQ(machine.getCurrentState(), machine.getReadyState());

    captureOutput(machine, 1, 500);

    EXPECT_EQ(machine.getCurrentState(), machine.getReadyState());
}
