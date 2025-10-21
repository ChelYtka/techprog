#include "Ruby.h"
#include <sstream>
#include <iomanip>

Ruby::Ruby(const std::string& name, double weight, double pricePerCarat,
           const std::string& color, int hardness, bool isRare,
           const std::string& origin, double fluorescence, bool hasInclusions)
    : PreciousGemstone(name, weight, pricePerCarat, color, hardness, isRare, origin),
      fluorescence(fluorescence), hasInclusions(hasInclusions) {}

double Ruby::getFluorescence() const { return fluorescence; }
bool Ruby::getHasInclusions() const { return hasInclusions; }

std::string Ruby::getDescription() const {
    std::ostringstream oss;
    oss << PreciousGemstone::getDescription() << "\n"
        << "  Флуоресценция: " << std::fixed << std::setprecision(1) << fluorescence << "%\n"
        << "  Включения: " << (hasInclusions ? "Есть" : "Нет") << "\n"
        << "  Редкость: " << (isRare ? "Да" : "Нет") << "\n"
        << "  Происхождение: " << origin;
    return oss.str();
}