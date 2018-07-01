/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include <math.h>
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

Vector3f Vector3f::operator+(const Vector3f &v) const
{
	return Vector3f(x + v.x, y + v.y, z + v.z);
}

Vector3f Vector3f::operator-(const Vector3f &v) const
{
	return Vector3f(x - v.x, y - v.y, z - v.z);
}

Vector3f Vector3f::operator*(const double &n) const
{
	return Vector3f(x * n, y * n, z * n);
}

Vector3f Vector3f::operator/(const double &n) const
{
	return Vector3f(x / n, y / n, z / n);
}

double Vector3f::getlength() const
{
	double tmp = x * x + y * y + z * z;
	return sqrt(tmp);
}

Vector3f Vector3f::normalize() const
{
	return Vector3f(*this / this->getlength());
}

double Vector3f::dot(const Vector3f &v) const
{
	return x * v.x + y * v.y + z * v.z;
}

Vector3f Vector3f::cross(const Vector3f &v) const
{
	return Vector3f(y * v.z - z * v.y,
			z * v.x - x * v.z,
			x * v.y - y * v.x);
}
