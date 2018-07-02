/*
** Raytracer by ReimuA
*/

#pragma once

#include <Vector3f.hpp>

class Ray {
public:
	Vector3f origin;
	Vector3f direction;

	Ray(const Vector3f &origin, const Vector3f &direction);
	~Ray();

};
