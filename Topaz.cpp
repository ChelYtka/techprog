#include "Topaz.h"
#include <sstream>
#include <iomanip>

Topaz::Topaz(const std::string& name, double weight, double pricePerCarat,
             const std::string& color, int hardness, bool isTransparent,
             const std::string& pattern, const std::string& pleochroism, bool isHeatTreated)
    : SemiPreciousGemstone(name, weight, pricePerCarat, color, hardness, isTransparent, pattern),
      _pleochroism(pleochroism), _isHeatTreated(isHeatTreated) {}

std::string Topaz::getPleochroism() const { return _pleochroism; }
bool Topaz::getIsHeatTreated() const { return _isHeatTreated; }

std::string Topaz::getDescription() const {
    std::ostringstream oss;
    oss << SemiPreciousGemstone::getDescription() << "\n"
        << "  Плеохроизм: " << _pleochroism << "\n"
        << "  Термическая обработка: " << (_isHeatTreated ? "Да" : "Нет") << "\n"
        << "  Прозрачность: " << (isTransparent ? "Прозрачный" : "Непрозрачный") << "\n"
        << "  Узор: " << pattern;
    return oss.str();
}