#pragma once

#include <string>

class Word
{
    private:
        std::string english;
        std::string russian;

    public:
        Word(const std::string& eng, const std::string& rus);

        std::string getEnglish();
        std::string getRussian();

        std::string toString() const;
        bool checkTranslation(const std::string& answer) const;
};
