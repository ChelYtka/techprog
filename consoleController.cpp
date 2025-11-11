#include "consoleController.h"
#include <iostream>

void ConsoleController::run() {

    bool running = true;
    while (running) {
        ConsoleView::showMainMenu();

        int choice = ConsoleView::getMenuChoice();

        switch (choice) {
            case 1:
                handleLearningSession();
                break;
            case 2:
                handleShowDictionary();
                break;
            case 3:
                handleAddWord();
                break;
            case 0:
                running = false;
                break;
            default:
                std::cout << "Неверный выбор!\n";
                break;
        }
    }

    std::cout << "До свидания!\n";
}

void ConsoleController::handleLearningSession() {
    auto words = dictionary.getAllWords();

    if (words.empty()) {
        std::cout << "Словарь пуст!\n";
        return;
    }

    std::cout << "\nНачинаем обучение (" << words.size() << " слов)...\n";

    for (const auto& word : words) {
        ConsoleView::showWord(word);
        std::string answer = ConsoleView::getAnswerInput();

        if (word->getRussian() == answer) {
            ConsoleView::showCorrectAnswer();
        } else {
            ConsoleView::showWrongAnswer(word->getRussian());
        }
    }

    ConsoleView::showSessionComplete();
}

void ConsoleController::handleShowDictionary() {
    auto words = dictionary.getAllWords();
    ConsoleView::showDictionary(words);
}

void ConsoleController::handleAddWord() {
    std::string english = ConsoleView::getEnglishWordInput();
    std::string russian = ConsoleView::getRussianWordInput();

    if (!english.empty() && !russian.empty()) {
        auto newWord = WordFactory::createWord(english, russian);
        dictionary.addWord(newWord);
        ConsoleView::showWordAdded();
    } else {
        std::cout << "Слово не может быть пустым!\n";
    }
}