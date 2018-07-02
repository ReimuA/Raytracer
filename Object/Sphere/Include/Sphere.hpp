/*
** Raytracer by ReimuA
*/

#pragma once

#include <string>
#include "IObject.hpp"

class Sphere : public IObject {
	Color _color;
	double _radius;
	Vector3f _center;
	bool _perturbation;
public:
	Sphere(const Vector3f &center, double radius, Color color, bool perturbation);
	~Sphere() override;

	void dump() const override;
	Color getColor(const Vector3f &normal) const override;
	Vector3f getNormal(const Vector3f &point) const override;
	Color getTexture(const Vector3f &normal) const override;
	virtual double computeIntersection(const Ray &ray) const override;
};

std::string getObjectName() __asm__("getObjectName");
IObject *createObject(const std::map<std::string, std::string> &map) __asm__("createObject");
