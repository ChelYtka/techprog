#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <algorithm>
#include <random>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , currentTrainingIndex(0)
    , trainingScore(0)
{
    ui->setupUi(this);

    showOnlyMainMenu();
    setupConnections();

    //dictionary.initializeBasicDictionary();
    // Не вызываем updateDictionaryDisplay() здесь, чтобы не дублировать
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupConnections()
{
    connect(ui->btnTraining, &QPushButton::clicked, this, &MainWindow::onBtnTrainingClicked);
    connect(ui->btnDictionary, &QPushButton::clicked, this, &MainWindow::onBtnDictionaryClicked);
    connect(ui->btnAddWord, &QPushButton::clicked, this, &MainWindow::onBtnAddWordClicked);
    connect(ui->btnExit, &QPushButton::clicked, this, &MainWindow::onBtnExitClicked);

    connect(ui->btnAddConfirm, &QPushButton::clicked, this, &MainWindow::onAddWordConfirm);
    connect(ui->btnAddCancel, &QPushButton::clicked, this, &MainWindow::onAddWordCancel);

    connect(ui->btnCheck, &QPushButton::clicked, this, &MainWindow::onTrainingCheck);
    connect(ui->btnExitTraining, &QPushButton::clicked, this, &MainWindow::onTrainingExit);
}

void MainWindow::showOnlyMainMenu()
{
    ui->groupBoxAddWord->setVisible(false);
    ui->groupBoxTraining->setVisible(false);
}

void MainWindow::appendToDisplay(const QString &text)
{
    ui->tableDictionary->append(text);
}

void MainWindow::onBtnTrainingClicked()
{
    if (dictionary.getWordCount() == 0) {
        QMessageBox::warning(this, "Предупреждение", "Словарь пуст!");
        return;
    }

    showOnlyMainMenu();
    ui->groupBoxTraining->setVisible(true);

    // Очищаем и показываем начало тренировки
    ui->tableDictionary->clear();
    appendToDisplay("Начало тренировки");
    startNewTraining();
}

void MainWindow::onBtnDictionaryClicked()
{
    showOnlyMainMenu();
    updateDictionaryDisplay();
}

void MainWindow::onBtnAddWordClicked()
{
    showOnlyMainMenu();
    ui->groupBoxAddWord->setVisible(true);
    ui->lineEditEnglish->clear();
    ui->lineEditRussian->clear();
}

void MainWindow::onBtnExitClicked()
{
    QApplication::quit();
}

void MainWindow::onAddWordConfirm()
{
    QString english = ui->lineEditEnglish->text().trimmed();
    QString russian = ui->lineEditRussian->text().trimmed();

    if (english.isEmpty() || russian.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Заполните оба поля!");
        return;
    }

    dictionary.addWord(std::make_shared<Word>(english.toStdString(), russian.toStdString()));

    // Очищаем и показываем обновленный словарь
    ui->tableDictionary->clear();
    appendToDisplay("Добавлено слово: " + english + " - " + russian);
    appendToDisplay("");

    showOnlyMainMenu();
    updateDictionaryDisplay(); // Показываем обновленный словарь
}

void MainWindow::onAddWordCancel()
{
    showOnlyMainMenu();
    // Показываем текущий словарь при отмене
    updateDictionaryDisplay();
}

void MainWindow::onTrainingCheck()
{
    if (currentTrainingIndex >= trainingWords.size()) {
        return;
    }

    QString answer = ui->lineEditTrainingAnswer->text().trimmed();
    std::string correctAnswer = trainingWords[currentTrainingIndex]->getRussian();

    QString englishWord = QString::fromStdString(trainingWords[currentTrainingIndex]->getEnglish());

    if (answer.toStdString() == correctAnswer) {
        trainingScore++;
        appendToDisplay(englishWord + " - " + answer + " верно");
    } else {
        appendToDisplay(englishWord + " - " + answer + " не верно");
        appendToDisplay("Правильно: " + QString::fromStdString(correctAnswer));
    }

    currentTrainingIndex++;

    if (currentTrainingIndex < trainingWords.size()) {
        showNextTrainingWord();
        ui->lineEditTrainingAnswer->clear();
    } else {
        appendToDisplay("");
        appendToDisplay("Тренировка завершена");
        appendToDisplay("Результат: " + QString::number(trainingScore) + " из " + QString::number(trainingWords.size()));
        showOnlyMainMenu();
    }
}

void MainWindow::onTrainingExit()
{
    showOnlyMainMenu();
    // Показываем словарь после выхода из тренировки
    updateDictionaryDisplay();
}

void MainWindow::updateDictionaryDisplay()
{
    auto words = dictionary.getAllWords();

    ui->tableDictionary->clear();

    if (words.empty()) {
        appendToDisplay("Словарь пуст. Добавьте слова.");
        return;
    }

    appendToDisplay("Словарь");
    appendToDisplay("Всего слов: " + QString::number(words.size()));
    appendToDisplay("");

    for (size_t i = 0; i < words.size(); ++i) {
        QString wordText = QString::number(i + 1) + ". " +
                           QString::fromStdString(words[i]->getEnglish()) + " - " +
                           QString::fromStdString(words[i]->getRussian());
        appendToDisplay(wordText);
    }
}

void MainWindow::startNewTraining()
{
    auto allWords = dictionary.getAllWords();
    if (allWords.empty()) return;

    trainingWords = allWords;
    std::random_shuffle(trainingWords.begin(), trainingWords.end());

    // if (trainingWords.size() > 5) {
    //     trainingWords.resize(5);
    // }

    currentTrainingIndex = 0;
    trainingScore = 0;

    ui->lineEditTrainingAnswer->clear();

    showNextTrainingWord();
}

void MainWindow::showNextTrainingWord()
{
    if (currentTrainingIndex < trainingWords.size()) {
        QString englishWord = QString::fromStdString(trainingWords[currentTrainingIndex]->getEnglish());

        // Показываем слово в labelWord
        ui->labelWord->setText(englishWord);

        // Также выводим в QTextBrowser
        appendToDisplay("");
        appendToDisplay("Слово " + QString::number(currentTrainingIndex + 1) +
                        " из " + QString::number(trainingWords.size()) + ":");
        appendToDisplay("Переведите: " + englishWord);
    }
}
