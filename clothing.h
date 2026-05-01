#pragma once
#include "text.h"

class Clothing {
private:
    Sentence* name;
    Sentence* brand;
    float price;
    int sizeValue;
public:
    Clothing(std::wstring n, std::wstring b, float p, int s);
    ~Clothing();
    float getPrice() const;
    int getSizeValue() const;
    std::wstring getName() const;
    std::wstring getBrand() const;
    bool isEqual(const Clothing& other) const;
};