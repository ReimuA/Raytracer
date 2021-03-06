/*
** Raytracer by ReimuA
*/

#include <map>
#include <string>
#include "Ray.hpp"
#include "Color.hpp"
#include "Vector3f.hpp"

#pragma once

class IObject {
public:
	IObject() = default;
	virtual ~IObject() = default;

	virtual void dump() const = 0;
	virtual Color getColor(const Vector3f &normal) const = 0;
	virtual Color getTexture(const Vector3f &normal) const = 0;
	virtual Vector3f getNormal(const Vector3f &point) const = 0;
	virtual double computeIntersection(const Ray &ray) const = 0;
};
