#include "SemiPreciousGemstone.h"

SemiPreciousGemstone::SemiPreciousGemstone(const std::string& name, double weight, double pricePerCarat,
                                           const std::string& color, int hardness, bool isTransparent,
                                           const std::string& pattern)
    : Gemstone(name, weight, pricePerCarat, color, hardness), isTransparent(isTransparent), pattern(pattern) {}

bool SemiPreciousGemstone::getIsTransparent() const { return isTransparent; }
std::string SemiPreciousGemstone::getPattern() const { return pattern; }
std::string SemiPreciousGemstone::getType() const { return "Полудрагоценный камень"; }