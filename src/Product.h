
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

/**
 * @brief Represents a product in the vending machine.
 */
class Product {
private:
    std::string name;
    int price;

public:
    /**
     * @brief Constructs a product.
     * @param name Product name.
     * @param price Product price in IQD.
     */
    Product(const std::string& name, int price);

    /**
     * @brief Returns the product name.
     * @return Product name.
     */
    std::string getName() const;

    /**
     * @brief Returns the product price.
     * @return Product price in IQD.
     */
    int getPrice() const;
};

#endif
