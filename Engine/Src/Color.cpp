/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "Color.hpp"

Color::Color(int _r, int _g, int _b, int _a) : r(_r), g(_g), b(_b), a(_a)
{
}

Color::Color(const Color &color) :
r(color.r),
g(color.g),
b(color.b),
a(color.a)
{
}

Color::~Color()
{
}
