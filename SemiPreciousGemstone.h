#pragma once

#include "Gemstone.h"

class SemiPreciousGemstone : public Gemstone {
protected:
    bool isTransparent; // прозрачность
    std::string pattern; // паттерн(шаблн)

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
    SemiPreciousGemstone(const std::string& name, double weight, double pricePerCarat,
    const std::string& color, int hardness, bool isRare, const std::string& origin);

    /* возврат прозрачности
    @return isTransparent
    */
    bool getIsTransparent() const;
    /* возврат шаблона
    @return pattern
    */
    std::string getPattern() const;
    /* возврат типа
    @return type
    */
    std::string getType() const;
};