/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#pragma once

#include <string>
#include <vector>

namespace StringHelper {
	void trimString(std::string&);
	void epureString(std::string&);
	void reduceString(std::string&);
	void epureStringVector(std::vector<std::string>&);
	std::vector<std::string> explodeString(const std::string str,
					const char c);
};