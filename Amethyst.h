#pragma once
#include "SemiPreciousGemstone.h"

class Amethyst : public SemiPreciousGemstone {
private:
    double _colorIntensity; // интенсивность цвета
    bool _isZoned; // находится в зоне

public:
    Amethyst(const std::string& name, double weight, double pricePerCarat,
             const std::string& color, int hardness, bool isTransparent,
             const std::string& pattern, double colorIntensity, bool isZoned);

    // возврат интенсивности цвета
    double getColorIntensity() const;
    // возврат нахождения в зоне
    bool getIsZoned() const;
    // возврат описания
    std::string getDescription() const;
};