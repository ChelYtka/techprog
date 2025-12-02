#pragma once

#include "dictionary.h"
#include "wordFactory.h"
#include "consoleView.h"

class ConsoleController {
private:
    Dictionary dictionary;

public:
    void run();

private:
    void handleLearningSession();
    void handleShowDictionary();
    void handleAddWord();
};