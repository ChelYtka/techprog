#include <iostream>
#include <memory>
#include "Gemstone.h"
#include "Diamond.h"
#include "Ruby.h"
#include "Amethyst.h"
#include "Topaz.h"


int main() {
    setlocale(LC_ALL, "Russian");

    Necklace necklace;

    std::cout << "Создание ожерелья из драгоценных и полудрагоценных камней...\n";

    auto diamond = make_shared<Diamond>("Бриллиант", 2.5, 5000.0, "Белый", 10, true, "Южная Африка", 'D', "Идеальная");
    auto ruby = make_shared<Ruby>("Рубин", 1.8, 3000.0, "Красный", 9, true, "Мьянма", 85.5, false);
    auto amethyst = make_shared<Amethyst>("Аметист", 3.0, 150.0, "Фиолетовый", 7, true, "Полосатый", 0.85, true);
    auto topaz = make_shared<Topaz>("Топаз", 2.8, 200.0, "Голубой", 8, true, "Однородный", "Слабый", true);

    necklace.addStone(diamond);
    necklace.addStone(ruby);
    necklace.addStone(amethyst);
    necklace.addStone(topaz);

    necklace.displayStones();

    cout << "\nУдаляем первый камень из ожерелья...\n";
    necklace.removeStone(0);

    necklace.displayStones();

    cout << "\nДобавляем новый бриллиант...\n";
    auto diamond2 = make_shared<Diamond>("Бриллиант", 1.5, 4500.0, "Желтый", 10, false, "Россия", 'F', "Хорошая");
    necklace.addStone(diamond2);

    necklace.displayStones();

    return 0;
}