#pragma once
#include "PreciousGemstone.h"

class Diamond : public PreciousGemstone {
private:
    char _clarity; // ясность
    std::string _cut; //разрез?

public:
    /* конструктор
    @param name имя
    @param weight вес
    @param pricePerCarat цена за карат
    @param color цвет
    @param hardness твёрдость
    @param isRare редкость
    @param origin происхождение
    */
    Diamond(const std::string& name, double weight, double pricePerCarat,
            const std::string& color, int hardness, bool isRare,
            const std::string& origin, char clarity, const std::string& cut);

    // возврат ясности
    char getClarity() const;
    // возврат разреза?
    std::string getCut() const;
    // возврат описания
    std::string getDescription() const;
};