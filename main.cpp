#include <iostream>
#include <vector>
#include <algorithm>
#include <fcntl.h>
#include <io.h>
#include "clothing.h"

void runAllTests();

int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    runAllTests();

    std::vector<Clothing*> clothes;
    clothes.push_back(new Clothing(L"Футболка", L"Nike", 850.5f, 42));
    clothes.push_back(new Clothing(L"Джинси", L"Levi's", 2100.0f, 34));
    clothes.push_back(new Clothing(L"Худі", L"Adidas", 1200.0f, 40));
    clothes.push_back(new Clothing(L"Куртка", L"Zara", 3500.0f, 48));

    std::sort(clothes.begin(), clothes.end(), [](Clothing* a, Clothing* b) {
        if (a->getPrice() != b->getPrice()) return a->getPrice() < b->getPrice();
        return a->getSizeValue() > b->getSizeValue();
        });

    std::wcout << L"\n--- Список одягу (відсортований) ---\n";
    for (auto c : clothes) {
        std::wcout << c->getName() << L" | " << c->getBrand() << L" | "
            << c->getPrice() << L" грн | Розмір: " << c->getSizeValue() << std::endl;
    }

    Clothing target(L"Джинси", L"Levi's", 2100.0f, 34);
    bool found = false;
    for (auto c : clothes) {
        if (c->isEqual(target)) { found = true; break; }
    }
    std::wcout << L"\nПошук ідентичного об'єкта: " << (found ? L"Знайдено!" : L"Ні") << std::endl;

    for (auto c : clothes) delete c;

    std::wcout << L"\nПрограма завершена. Натисніть будь-яку клавішу...";

    _setmode(_fileno(stdout), _O_TEXT);

    system("pause > nul"); 
    return 0;
}