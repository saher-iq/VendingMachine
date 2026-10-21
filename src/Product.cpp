
#include "Product.h"

Product::Product(const std::string& name, int price)
    : name(name), price(price) {
}

std::string Product::getName() const {
    return name;
}

int Product::getPrice() const {
    return price;
}
