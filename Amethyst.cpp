#include "Amethyst.h"
#include <sstream>
#include <iomanip>

Amethyst::Amethyst(const std::string& name, double weight, double pricePerCarat,
                   const std::string& color, int hardness, bool isTransparent,
                   const std::string& pattern, double colorIntensity, bool isZoned)
    : SemiPreciousGemstone(name, weight, pricePerCarat, color, hardness, isTransparent, pattern),
      _colorIntensity(colorIntensity), _isZoned(isZoned) {}

double Amethyst::getColorIntensity() const { return _colorIntensity; }
bool Amethyst::getIsZoned() const { return _isZoned; }

std::string Amethyst::getDescription() const {
    std::ostringstream oss;
    oss << SemiPreciousGemstone::getDescription() << "\n"
        << "  Интенсивность цвета: " << std::fixed << std::setprecision(2) << _colorIntensity << "\n"
        << "  Зональность: " << (_isZoned ? "Есть" : "Нет") << "\n"
        << "  Прозрачность: " << (isTransparent ? "Прозрачный" : "Непрозрачный") << "\n"
        << "  Узор: " << pattern;
    return oss.str();
}