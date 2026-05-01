#include "text.h"
#include <cwctype>

Letter::Letter(wchar_t s) : symbol(s) {}
wchar_t Letter::getChar() const { return symbol; }

Word::Word(const std::wstring& s) {
    for (wchar_t c : s) letters.push_back(Letter(c));
}
std::wstring Word::getString() const {
    std::wstring s = L"";
    for (const auto& l : letters) s += l.getChar();
    return s;
}

Punctuation::Punctuation(wchar_t m) : mark(m) {}
std::wstring Punctuation::getString() const { return std::wstring(1, mark); }

Sentence::Sentence(const std::wstring& input) {
    std::wstring currentWord = L"";
    bool lastWasSpace = false;
    for (wchar_t c : input) {
        if (iswalpha(c) || iswdigit(c)) {
            currentWord += c;
            lastWasSpace = false;
        }
        else {
            if (!currentWord.empty()) {
                elements.push_back(new Word(currentWord));
                currentWord = L"";
            }
            if (iswspace(c)) {
                if (!lastWasSpace) {
                    elements.push_back(new Punctuation(L' '));
                    lastWasSpace = true;
                }
            }
            else {
                elements.push_back(new Punctuation(c));
                lastWasSpace = false;
            }
        }
    }
    if (!currentWord.empty()) elements.push_back(new Word(currentWord));
}

Sentence::~Sentence() {
    for (auto e : elements) delete e;
}

std::wstring Sentence::getString() const {
    std::wstring s = L"";
    for (const auto& e : elements) s += e->getString();
    return s;
}