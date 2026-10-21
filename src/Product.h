
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    std::string name;
    int price;

public:
    Product(const std::string& name, int price);

    std::string getName() const;
    int getPrice() const;
};

#endif
