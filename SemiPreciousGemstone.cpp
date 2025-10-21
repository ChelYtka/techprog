#include "SemiPreciousGemstone.h"

SemiPreciousGemstone::SemiPreciousGemstone(const std::string& name, double weight, double pricePerCarat,
                                           const std::string& color, int hardness, bool isTransparent,
                                           const std::string& pattern)
    : Gemstone(name, weight, pricePerCarat, color, hardness), _isTransparent(isTransparent), _pattern(pattern) {}

bool SemiPreciousGemstone::getIsTransparent() const { return _isTransparent; }
std::string SemiPreciousGemstone::getPattern() const { return _pattern; }
std::string SemiPreciousGemstone::getType() const { return "Полудрагоценный камень"; }