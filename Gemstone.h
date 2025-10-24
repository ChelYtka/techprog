#pragma once

#include <string>

class Gemstone {
private:
    std::string _name; // название камня
    double _weight; // вес камня
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

     std::string getName() const;
    double getWeight() const;
    double getPricePerCarat() const;
    std::string getColor() const;
    int getHardness() const;

    double calculatePrice() const;
    std::string getDescription() const;
    std::string getType() const;

};