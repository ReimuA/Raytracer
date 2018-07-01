/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#pragma once

class Vector3f {
public:
	double x;
	double y;
	double z;

	Vector3f(double x = 0, double y = 0, double z = 0);
	Vector3f(const Vector3f &vector);
	~Vector3f();

	double getlength() const;
	Vector3f normalize() const;
	double dot(const Vector3f &vector) const;
	Vector3f cross(const Vector3f &vector) const;


	Vector3f operator+(const Vector3f& vector) const;
	Vector3f operator-(const Vector3f& vector) const;
	Vector3f operator*(const double &n) const;
	Vector3f operator/(const double &n) const;
};
