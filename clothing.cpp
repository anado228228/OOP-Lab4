#include "clothing.h"

Clothing::Clothing(std::wstring n, std::wstring b, float p, int s) : price(p), sizeValue(s) {
    name = new Sentence(n);
    brand = new Sentence(b);
}
Clothing::~Clothing() {
    delete name;
    delete brand;
}
float Clothing::getPrice() const { return price; }
int Clothing::getSizeValue() const { return sizeValue; }
std::wstring Clothing::getName() const { return name->getString(); }
std::wstring Clothing::getBrand() const { return brand->getString(); }
bool Clothing::isEqual(const Clothing& other) const {
    return getName() == other.getName() && getBrand() == other.getBrand() &&
        price == other.price && sizeValue == other.sizeValue;
}