#pragma once

#include <vector>
#include <memory>
#include "word.h"

class ConsoleView {
public:
    static void showMainMenu();
    static void showWord(const std::shared_ptr<Word>& word);
    static void showCorrectAnswer();
    static void showWrongAnswer(const std::string& correctAnswer);
    static void showDictionary(const std::vector<std::shared_ptr<Word>>& words);
    static void showWordAdded();
    static void showSessionComplete();

    static std::string getEnglishWordInput();
    static std::string getRussianWordInput();
    static std::string getAnswerInput();
    static int getMenuChoice();
};