/*
** Raytracer by ReimuA
*/

#include <map>
#include <string>
#include <functional>
#include "IObject.hpp"

class ObjectFactory {
	std::map<std::string, std::function<IObject *(const std::map<std::string, std::string> &map)>> _factory;

public:
	ObjectFactory();
	~ObjectFactory();
};
