#include <cassert>
#include <iostream>
#include "text.h"
#include "clothing.h"

void runAllTests() {
    std::wcout << L"Запуск тестів...\n";
    Sentence s(L"Тест    пробілів");
    assert(s.getString() == L"Тест пробілів");
    Clothing c1(L"Т", L"Б", 10.0f, 1);
    assert(c1.getPrice() == 10.0f);
    std::wcout << L"Усі тести пройдено успішно!\n";
}