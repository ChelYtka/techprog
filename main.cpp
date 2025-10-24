#include <iostream>
#include <memory>
#include "Gemstone.h"
#include "Diamond.h"
#include "Ruby.h"
#include "Amethyst.h"
#include "Topaz.h"
#include "Necklace.h"


int main() {
    setlocale(LC_ALL, "Russian");

    Necklace necklace;

    std::cout << "Создание ожерелья из драгоценных и полудрагоценных камней...\n";

    auto diamond = std::make_shared<Diamond>("Бриллиант", 2.5, 5000.0, "Белый", 10, true, "Южная Африка", 'D', "Идеальная");
    auto ruby = std::make_shared<Ruby>("Рубин", 1.8, 3000.0, "Красный", 9, true, "Мьянма", 85.5, false);
    auto amethyst = std::make_shared<Amethyst>("Аметист", 3.0, 150.0, "Фиолетовый", 7, true, "Полосатый", 0.85, true);
    auto topaz = std::make_shared<Topaz>("Топаз", 2.8, 200.0, "Голубой", 8, true, "Однородный", "Слабый", true);

    necklace.addStone(diamond.get());
    necklace.addStone(ruby.get());
    necklace.addStone(amethyst.get());
    necklace.addStone(topaz.get());

    necklace.displayStones();
    return 0;
}