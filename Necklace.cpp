#include "Necklace.h"
#include <iostream>
#include <iomanip>

void Necklace::addStone(Gemstone* stone) {
    _stones.push_back(stone);
}

void Necklace::removeStone(int index) {
    if (index >= 0 && index < _stones.size()) {
        _stones.erase(_stones.begin() + index);
    }
}

void Necklace::clearNecklace() {
    _stones.clear();
}

double Necklace::getTotalWeight() const {
    double total = 0.0;
    for (const auto& stone : _stones) {
        total += stone->getWeight();
    }
    return total;
}

double Necklace::getTotalPrice() const {
    double total = 0.0;
    for (const auto& stone : _stones) {
        total += stone->calculatePrice();
    }
    return total;
}

void Necklace::displayStones() const {
    std::cout << "\n=== Камни в ожерелье ===\n";
    for (size_t i = 0; i < _stones.size(); ++i) {
        std::cout << _stones[i]->getDescription() << "\n";
    }
    std::cout << "Общий вес: " << std::fixed << std::setprecision(2) << getTotalWeight() << " карат\n";
    std::cout << "Общая стоимость: $" << std::fixed << std::setprecision(2) << getTotalPrice() << "\n";
}

size_t Necklace::getStoneCount() const {
    return _stones.size();
}