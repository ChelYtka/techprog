#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextBrowser>
#include "dictionary.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onBtnTrainingClicked();
    void onBtnDictionaryClicked();
    void onBtnAddWordClicked();
    void onBtnExitClicked();

    void onAddWordConfirm();
    void onAddWordCancel();

    void onTrainingCheck();
    void onTrainingExit();

private:
    Ui::MainWindow *ui;
    Dictionary dictionary;

    std::vector<std::shared_ptr<Word>> trainingWords;
    int currentTrainingIndex;
    int trainingScore;

    void showOnlyMainMenu();
    void setupConnections();
    void updateDictionaryDisplay();
    void startNewTraining();
    void showNextTrainingWord();

    // Добавляем объявление этого метода
    void appendToDisplay(const QString &text);
};

#endif // MAINWINDOW_H
