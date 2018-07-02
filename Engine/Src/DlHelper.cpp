/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#include <string>
#include <dlfcn.h>
#include <stdexcept>
#include "DlHelper.hpp"

void *DlHelper::dlOpen(const std::string &str)
{
	void *handle = dlopen(str.c_str(), RTLD_NOW);

	if (handle == NULL)
		throw std::invalid_argument("Can't open " + str + " : "
			+ dlerror());
	return handle;
}

void *DlHelper::dlSym(void *handle, const std::string &str)
{
	void *sym = dlsym(handle, str.c_str());

	if (sym == NULL)
		throw std::invalid_argument("Can't load symbol " + str + " : "
			+ dlerror());
	return sym;
}

void DlHelper::dlClose(void *handle)
{
	if (dlclose(handle))
		throw std::invalid_argument("Can't close library : " +
			std::string(dlerror()));
}
