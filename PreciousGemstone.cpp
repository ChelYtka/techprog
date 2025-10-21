#include "PreciousGemstone.h"

PreciousGemstone::PreciousGemstone(const std::string& name, double weight, double pricePerCarat,
                                   const std::string& color, int hardness, bool isRare,
                                   const std::string& origin)
    : Gemstone(name, weight, pricePerCarat, color, hardness), _isRare(isRare), _origin(origin) {}

bool PreciousGemstone::getIsRare() const { return _isRare; }
std::string PreciousGemstone::getOrigin() const { return _origin; }
std::string PreciousGemstone::getType() const { return "Драгоценный камень"; }