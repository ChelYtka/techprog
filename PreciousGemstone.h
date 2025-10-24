#pragma once

#include "Gemstone.h"

class PreciousGemstone : public Gemstone {
protected:
    bool isRare; // редкий или нет
    std::string origin; // происхождение

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
    PreciousGemstone(const std::string& name, double weight, double pricePerCarat,
    const std::string& color, int hardness, bool isRare, const std::string& origin);

    /* возврат редкости камня
    @return isRare
    */
    bool getIsRare() const;
    /* возврат происхождения
    @return origin
    */
    std::string getOrigin() const;
    /* возврат типа
    @return type
    */
    std::string getType() const;
};