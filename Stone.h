#pragma once

#include <iostream>
#include <string>

/// @brief Класс камня
class Stone
{
    protected:
        std::string _name; // название камня
        float _weithCarats; // вес в каратах
        float _pricePerCarat; // цена в каратах

    public:
        /// @brief конструктор класса камня
        /// @param name название
        /// @param weight вес
        /// @param price цена
        Stone(const std::string& name, float weight, float price) :
            _name(name), _weithCarats(weight), _pricePerCarat(price) {}

        /// @brief деструктор класса камня
        virtual ~Stone() = default;
};