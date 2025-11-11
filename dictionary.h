#pragma once

#include "word.h"
#include <vector>
#include <memory>

class Dictionary {
private:
    std::vector<std::shared_ptr<Word>> words;

public:
    Dictionary();

    void addWord(std::shared_ptr<Word> word);
    std::vector<std::shared_ptr<Word>> getAllWords() const;
    size_t getWordCount() const;

    void initializeBasicDictionary();
};