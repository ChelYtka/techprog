#include "Gemstone.h"
#include <sstream>
#include <iomanip>

Gemstone::Gemstone(const std::string& name, double weight, double pricePerCarat,
                   const std::string& color, int hardness)
    : _name(name), _weight(weight), _pricePerCarat(pricePerCarat), _color(color), _hardness(hardness) {}\

Gemstone::~Gemstone() {}

std::string Gemstone::getName() const { return _name; }
double Gemstone::getWeight() const { return _weight; }
double Gemstone::getPricePerCarat() const { return _pricePerCarat; }
std::string Gemstone::getColor() const { return _color; }
int Gemstone::getHardness() const { return _hardness; }
std::string Gemstone::getType() const {return "Dimond"; };

double Gemstone::calculatePrice() const {
    return _weight * _pricePerCarat;
}

std::string Gemstone::getDescription() const {
    std::ostringstream oss;
    oss << _name
        << "  Вес: " << std::fixed << std::setprecision(2) << _weight << " карат"
        << "  Цвет: " << _color
        << "  Твердость: " << _hardness << " по Моосу"
        << "  Цена за карат: $" << std::fixed << std::setprecision(2) << _pricePerCarat
        << "  Общая стоимость: $" << std::fixed << std::setprecision(2) << calculatePrice();
    return oss.str();
}