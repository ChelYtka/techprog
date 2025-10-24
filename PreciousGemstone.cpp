#include "PreciousGemstone.h"

PreciousGemstone::PreciousGemstone(const std::string& name, double weight, double pricePerCarat,
                                   const std::string& color, int hardness, bool isRare,
                                   const std::string& origin)
    : Gemstone(name, weight, pricePerCarat, color, hardness), isRare(isRare), origin(origin) {}

bool PreciousGemstone::getIsRare() const { return isRare; }
std::string PreciousGemstone::getOrigin() const { return origin; }
std::string PreciousGemstone::getType() const { return "Драгоценный камень"; }