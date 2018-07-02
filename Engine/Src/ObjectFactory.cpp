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
	std::string(*fptr)();
	void *handler = DlHelper::dlOpen(path);
	*(void **)(&fptr) = (std::string *)DlHelper::dlSym(handler, "getObjectName");

	std::string str = fptr();
	std::cout << str << std::endl;

}
