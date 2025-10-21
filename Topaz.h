#pragma once
#include "SemiPreciousGemstone.h"

class Topaz : public SemiPreciousGemstone {
private:
    std::string _pleochroism; // окраска
    bool _isHeatTreated; // подвержен термообработке

public:
    Topaz(const std::string& name, double weight, double pricePerCarat,
          const std::string& color, int hardness, bool isTransparent,
          const std::string& pattern, const std::string& pleochroism, bool isHeatTreated);

    std::string getPleochroism() const;
    bool getIsHeatTreated() const;
    std::string getDescription() const;
};