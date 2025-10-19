#pragma once

#include <string>

class Gemstone {
private:
    std::string name; // название камня
    double weithg; // вес камня
    double _pricePerCarat; // стоимость карата
    std::string _color; // цвет
    int _hardness; // твёрдость камня

public:
    /* конструктор
    @param name имя
    @param weight вес
    @param pricePerCarat цена за карат
    @param color цвет
    @param hardness твёрдость
    */
    Gemstone(const std::string& name, double weight, double pricePerCarat,
    const std::string& color, int hardness);
    ~Gemstone();

    /*возврат имени
    @return name
    */
    std::string getName() const;
    /*возврат веса
    @return weight
    */
    double getWeight() const;
    /*возврат цены
    @return price
    */
    double getPrice() const;
};