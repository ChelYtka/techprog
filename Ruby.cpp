#include "Ruby.h"
#include <sstream>
#include <iomanip>

Ruby::Ruby(const std::string& name, double weight, double pricePerCarat,
           const std::string& color, int hardness, bool isRare,
           const std::string& origin, double fluorescence, bool hasInclusions)
    : PreciousGemstone(name, weight, pricePerCarat, color, hardness, isRare, origin),
      _fluorescence(fluorescence), _hasInclusions(hasInclusions) {}

double Ruby::getFluorescence() const { return _fluorescence; }
bool Ruby::getHasInclusions() const { return _hasInclusions; }

std::string Ruby::getDescription() const {
    std::ostringstream oss;
    oss << PreciousGemstone::getDescription() << "\n"
        << "  Флуоресценция: " << std::fixed << std::setprecision(1) << _fluorescence << "%\n"
        << "  Включения: " << (_hasInclusions ? "Есть" : "Нет") << "\n"
        << "  Редкость: " << (isRare ? "Да" : "Нет") << "\n"
        << "  Происхождение: " << origin;
    return oss.str();
}