#include "Diamond.h"
#include <sstream>
#include <iomanip>

Diamond::Diamond(const std::string& name, double weight, double pricePerCarat,
                 const std::string& color, int hardness, bool isRare,
                 const std::string& origin, char clarity, const std::string& cut)
    : PreciousGemstone(name, weight, pricePerCarat, color, hardness, isRare, origin),
      clarity(clarity), cut(cut) {}

char Diamond::getClarity() const { return clarity; }
std::string Diamond::getCut() const { return cut; }

std::string Diamond::getDescription() const {
    std::ostringstream oss;
    oss << PreciousGemstone::getDescription() << "\n"
        << "  Чистота: " << clarity << "\n"
        << "  Огранка: " << cut << "\n"
        << "  Редкость: " << (isRare ? "Да" : "Нет") << "\n"
        << "  Происхождение: " << origin;
    return oss.str();
}