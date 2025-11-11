#include "word.h"

Word::Word(const std::string& eng, const std::string& rus):
    english(eng), russian(rus) {}

std::string Word::getEnglish()
{
    return english;
}

std::string Word::getRussian()
{
    return russian;
}