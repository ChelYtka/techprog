#pragma once
#include "PreciousGemstone.h"

class Ruby : public PreciousGemstone {
private:
    double _fluorescence; // свечение
    bool _hasInclusions; // включения

public:
    Ruby(const std::string& name, double weight, double pricePerCarat,
         const std::string& color, int hardness, bool isRare,
         const std::string& origin, double fluorescence, bool hasInclusions);

    // возврат свечения
    double getFluorescence() const;
    // возврат включений
    bool getHasInclusions() const;
    // возврат описания
    std::string getDescription() const;
};