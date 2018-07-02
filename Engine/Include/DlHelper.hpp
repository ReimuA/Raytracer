/*
** EPITECH PROJECT, 2018
**  <------------>
** File description:
**    <------->
*/

#pragma once

#include <string>

namespace DlHelper {
	void dlClose(void *handle);
	void *dlSym(void *handle, const std::string &str);
	void *dlOpen(const std::string &str);
};
