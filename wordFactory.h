#pragma once

#include "word.h"
#include <memory>

class WordFactory {
public:
    static std::shared_ptr<Word> createWord(const std::string& english,
                                           const std::string& russian);
};