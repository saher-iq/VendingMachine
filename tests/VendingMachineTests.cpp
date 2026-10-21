
#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

#include "Product.h"
#include "VendingMachine.h"

// Test 1: Check product name and price
TEST(ProductTests, WaterHasCorrectNameAndPrice) {
    Product water("Water", 500);

    EXPECT_EQ(water.getName(), "Water");
    EXPECT_EQ(water.getPrice(), 500);
}

// Test 2: Check that a valid product can be selected
TEST(VendingMachineTests, ValidProductCanBeSelected) {
    VendingMachine machine;

    EXPECT_NE(machine.getProduct(1), nullptr);
    EXPECT_NE(machine.getProduct(2), nullptr);
    EXPECT_NE(machine.getProduct(3), nullptr);
}

// Test 3: Invalid product choice should return nullptr
TEST(VendingMachineTests, InvalidProductReturnsNullptr) {
    VendingMachine machine;

    EXPECT_EQ(machine.getProduct(0), nullptr);
    EXPECT_EQ(machine.getProduct(4), nullptr);
}

// Test 4: Buying with insufficient money should report an error
TEST(VendingMachineTests, InsufficientMoneyShowsMessage) {
    VendingMachine machine;

    std::ostringstream output;
    std::streambuf* oldOutput = std::cout.rdbuf(output.rdbuf());

    machine.buyProduct(1, 200);

    std::cout.rdbuf(oldOutput);

    EXPECT_NE(
        output.str().find("Not enough money!"),
        std::string::npos
    );
}

// Test 5: Buying with enough money should succeed

TEST(VendingMachineTests, SufficientMoneyCompletesPurchase) {
    VendingMachine machine;

    std::ostringstream output;
    std::streambuf* oldOutput = std::cout.rdbuf(output.rdbuf());

    try {
        machine.buyProduct(1, 500);
    }
    catch (...) {
        std::cout.rdbuf(oldOutput);
        throw;
    }

    std::cout.rdbuf(oldOutput);

    EXPECT_NE(
        output.str().find("Purchase successful!"),
        std::string::npos
    );

    EXPECT_NE(
        output.str().find("Change: 0 IQD"),
        std::string::npos
    );
}

