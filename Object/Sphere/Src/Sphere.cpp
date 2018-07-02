/*
** Raytracer by ReimuA
*/

#include <map>
#include <math.h>
#include <string>
#include "Sphere.hpp"

IObject *createObject(const std::map<std::string, std::string> &map)
{
	return new Sphere(Vector3f(3, 3, 3), 5, Color(122, 122, 122, 255), false);
}

std::string getObjectName()
{
	return "Sphere";
}

Sphere::Sphere(const Vector3f &center, double radius, Color color, bool perturabtion) :
_color(color),
_radius(radius),
_center(center),
_perturbation(perturabtion)
{
}

Sphere::~Sphere()
{
}

void Sphere::dump() const
{
}

Color Sphere::getColor(const Vector3f &normal) const
{
	(void)normal;
	return _color;
}

Vector3f Sphere::getNormal(const Vector3f &point) const
{
	Vector3f vector = point * -1;
	vector = vector + point;
	vector = vector.normalize();
	return vector;
}

Color Sphere::getTexture(const Vector3f &normal) const
{
	(void)normal;
	return _color;
}


double Sphere::computeIntersection(const Ray &ray) const
{
	double a = ray.direction.x * ray.direction.x + ray.direction.z * ray.direction.z + ray.direction.y * ray.direction.y;
	double b = (2 * (ray.origin.x - _center.x) * ray.direction.x) +
			(2 * (ray.origin.y - _center.y) * ray.direction.y) +
			(2 * (ray.origin.z - _center.z) * ray.direction.z);
	double c = pow(ray.origin.x - _center.x, 2) +
		pow(ray.origin.y - _center.y, 2) +
		pow(ray.origin.z - _center.z, 2) -
		(_radius * _radius);

	double delta = b * b - 4 * a * c;

	if (delta < 0)
		return -1;
	double x1 = ((-b - sqrt(delta)) / (2 * a)) - 0.000001;
	double x2 = ((-b + sqrt(delta)) / (2 * a)) - 0.000001;
	if (x1 < 0 && x2 < 0)
		return -1;
	return x1 > x2 ? x2 : x1;
}
