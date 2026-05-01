#pragma once
#include <vector>
#include <string>

class SentenceElement {
public:
    virtual ~SentenceElement() {}
    virtual std::wstring getString() const = 0;
};

class Letter {
private:
    wchar_t symbol;
public:
    Letter(wchar_t s);
    wchar_t getChar() const;
};

class Word : public SentenceElement {
private:
    std::vector<Letter> letters;
public:
    Word(const std::wstring& s);
    std::wstring getString() const override;
};

class Punctuation : public SentenceElement {
private:
    wchar_t mark;
public:
    Punctuation(wchar_t m);
    std::wstring getString() const override;
};

class Sentence {
private:
    std::vector<SentenceElement*> elements;
public:
    Sentence(const std::wstring& input);
    ~Sentence();
    std::wstring getString() const;
};