/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include "Vector3f.hpp"

Vector3f::Vector3f(double _x, double _y, double _z) : x(_x), y(_y), z(_z)
{
}

Vector3f::Vector3f(const Vector3f &vector) :
x(vector.x),
y(vector.y),
z(vector.z)
{
}

Vector3f::~Vector3f()
{
}

Vector3f Vector3f::operator+(const Vector3f& v) const
{
	return Vector3f(x + v.x, y + v.y, z + v.z);
}

Vector3f Vector3f::operator-(const Vector3f& v) const
{
	return Vector3f(x - v.x, y - v.y, z - v.z);
}
