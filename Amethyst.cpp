#include "Amethyst.h"
#include <sstream>
#include <iomanip>

Amethyst::Amethyst(const std::string& name, double weight, double pricePerCarat,
                   const std::string& color, int hardness, bool isTransparent,
                   const std::string& pattern, double colorIntensity, bool isZoned)
    : SemiPreciousGemstone(name, weight, pricePerCarat, color, hardness, isTransparent, pattern),
      colorIntensity(colorIntensity), isZoned(isZoned) {}

double Amethyst::getColorIntensity() const { return colorIntensity; }
bool Amethyst::getIsZoned() const { return isZoned; }

std::string Amethyst::getDescription() const {
    std::ostringstream oss;
    oss << SemiPreciousGemstone::getDescription() << "\n"
        << "  Интенсивность цвета: " << std::fixed << std::setprecision(2) << colorIntensity << "\n"
        << "  Зональность: " << (isZoned ? "Есть" : "Нет") << "\n"
        << "  Прозрачность: " << (isTransparent ? "Прозрачный" : "Непрозрачный") << "\n"
        << "  Узор: " << pattern;
    return oss.str();
}