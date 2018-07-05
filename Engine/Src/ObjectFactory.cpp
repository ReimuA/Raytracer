/*
** Raytracer by ReimuA
*/

#include <iostream>
#include "DlHelper.hpp"
#include "StringHelper.hpp"
#include "ObjectFactory.hpp"

ObjectFactory::ObjectFactory() : _factory()
{
}

ObjectFactory::~ObjectFactory()
{
}

void ObjectFactory::feed(const std::string &path)
{
	IObject *(*createObject)(const std::map<std::string, std::string>);
	std::string(*getObjectName)();
	void *handler = DlHelper::dlOpen(path);
	*(void **)(&createObject) = (IObject *)DlHelper::dlSym(handler, "createObject");
	*(void **)(&getObjectName) = (std::string *)DlHelper::dlSym(handler, "getObjectName");

	_factory[getObjectName()] = createObject;
	std::cout << getObjectName() << std::endl;
}
