#include "consoleView.h"
#include <iostream>


void ConsoleView::showMainMenu() {
    std::cout << "1. Начать обучение\n";
    std::cout << "2. Показать словарь\n";
    std::cout << "3. Добавить слово\n";
    std::cout << "0. Выход\n";
    std::cout << "Выберите действие: ";
}

void ConsoleView::showWord(const std::shared_ptr<Word>& word) {
    if (word) {
        std::cout << "\nАнглийское слово: " << word->getEnglish() << std::endl;
    }
}

void ConsoleView::showCorrectAnswer() {
    std::cout << "Правильно!\n";
}

void ConsoleView::showWrongAnswer(const std::string& correctAnswer) {
    std::cout << "Неправильно. Правильно: " << correctAnswer << "\n";
}

void ConsoleView::showDictionary(const std::vector<std::shared_ptr<Word>>& words) {
    std::cout << "\nСЛОВАРЬ (" << words.size() << " слов):\n";

    for (size_t i = 0; i < words.size(); ++i) {
        const auto& word = words[i];
        std::cout << (i + 1) << ". " << word->getEnglish()
                  << " - " << word->getRussian() << "\n";
    }
}

void ConsoleView::showWordAdded() {
    std::cout << "Слово добавлено!\n";
}

void ConsoleView::showSessionComplete() {
    std::cout << "\nОбучение завершено!\n";
}

std::string ConsoleView::getEnglishWordInput() {
    std::string input;
    std::cout << "Введите английское слово: ";
    std::getline(std::cin, input);
    return input;
}

std::string ConsoleView::getRussianWordInput() {
    std::string input;
    std::cout << "Введите русский перевод: ";
    std::getline(std::cin, input);
    return input;
}

std::string ConsoleView::getAnswerInput() {
    std::string input;
    std::cout << "Введите перевод: ";
    std::getline(std::cin, input);
    return input;
}

int ConsoleView::getMenuChoice() {
    int choice;
    std::cin >> choice;
    //std::cin.ignore();
    return choice;
}