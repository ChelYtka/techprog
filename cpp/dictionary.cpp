        #include "dictionary.h"

        Dictionary::Dictionary() {
            initializeBasicDictionary();
        }

        void Dictionary::addWord(std::shared_ptr<Word> word) {
            words.push_back(word);
        }

        std::vector<std::shared_ptr<Word>> Dictionary::getAllWords() const {
            return words;
        }

        size_t Dictionary::getWordCount() const {
            return words.size();
        }

        void Dictionary::initializeBasicDictionary() {
            words.push_back(std::make_shared<Word>("hello", "привет"));
            words.push_back(std::make_shared<Word>("world", "мир"));
            words.push_back(std::make_shared<Word>("computer", "компьютер"));
            words.push_back(std::make_shared<Word>("book", "книга"));
            words.push_back(std::make_shared<Word>("house", "дом"));
        }

        std::shared_ptr<Word> Dictionary::getWordAt(int index) const {
            if (index >= 0 && index < static_cast<int>(words.size())) {
                return words[index];
            }
            return nullptr;
        }

        std::string Dictionary::findTranslation(const std::string& english) const {
            for (const auto& word : words) {
                if (word->getEnglish() == english) {
                    return word->getRussian();
                }
            }
            return "Слово не найдено";
        }
