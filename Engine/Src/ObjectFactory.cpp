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
	IObject *(*createObject)();
	std::string(*getObjectName)();
	void *handler = DlHelper::dlOpen(path);
	*(void **)(&createObject) = (IObject *)DlHelper::dlSym(handler, "createObject");
	*(void **)(&getObjectName) = (std::string *)DlHelper::dlSym(handler, "getObjectName");

	std::string str = getObjectName();
	IObject *obj = createObject();
	obj->dump();
	std::cout << str << std::endl;
}
