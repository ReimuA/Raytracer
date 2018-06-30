/*
** EPITECH PROJECT, 2018
** singe
** File description:
** singe
*/

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include "StringHelper.hpp"

void StringHelper::trimString(std::string &str)
{
	const std::size_t comment = str.find_first_of('#');

	if (comment != std::string::npos)
		str.erase(str.find_first_of('#'));
	for (unsigned int i = 0; i < str.size(); i++) {
		if (str[i] == '\t' || str[i] == '\n')
			str[i] = ' ';
	}
	const std::size_t strBegin = str.find_first_not_of(' ');
	const std::size_t strEnd = str.find_last_not_of(' ');

	if (strBegin == std::string::npos)
		str = "";
	else {
		str = str.substr(strBegin, strEnd - strBegin + 1);
	}
}

void StringHelper::reduceString(std::string &str)
{
	auto beginSpace = str.find_first_of(' ');

	while (beginSpace != std::string::npos) {
		std::size_t endSpace = str.find_first_not_of(' ', beginSpace);
		std::size_t range = endSpace - beginSpace;

		str.replace(beginSpace, range, " ");

		std::size_t newStart = beginSpace + std::string(" ").length();
		beginSpace = str.find_first_of(' ', newStart);
	}
	if (str == " ")
		str = "";
}

void StringHelper::epureString(std::string &str)
{
	trimString(str);
	reduceString(str);
}

void StringHelper::epureStringVector(std::vector<std::string> &strVector)
{
	for (unsigned int i = 0; i < strVector.size(); i++)
		epureString(strVector[i]);
}

std::vector<std::string> StringHelper::explodeString(const std::string str,
						 const char c)
{
    std::string epured = str;
    StringHelper::epureString(epured);
    std::istringstream split(epured);
    std::vector<std::string> tokens;

    for (std::string s; std::getline(split, s, c); tokens.push_back(s));
    if (tokens.size() == 0)
    	tokens.push_back("");
    return tokens;
}
