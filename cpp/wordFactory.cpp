    #include "wordFactory.h"

    std::shared_ptr<Word> WordFactory::createWord(const std::string& english,
                                                 const std::string& russian) {
        return std::make_shared<Word>(english, russian);
    }
