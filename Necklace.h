#pragma once
#include "Gemstone.h"
#include <vector>

class Necklace {
private:
    std::vector<Gemstone*> _stones;

public:
    void addStone(Gemstone* stone);
    void removeStone(int index);
    void clearNecklace();

    double getTotalWeight() const;
    double getTotalPrice() const;
    void displayStones() const;
    size_t getStoneCount() const;
};