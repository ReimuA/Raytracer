/*
** Raytracer by ReimuA
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include "Parser.hpp"
#include "StringHelper.hpp"

Parser::Parser() : _fileContent()
{
}

Parser::~Parser()
{
}

void Parser::loadFile(const std::string &fileName)
{
	std::ifstream file(fileName);
	if (!file)
		throw ParserException("Cannot load file");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	_fileContent = buffer.str();
}

void Parser::makeMap(const std::string &str)
{
	std::vector<std::string> objectParam = StringHelper::explodeString(str, ',');
	std::map<std::string, std::string> map;

	StringHelper::epureStringVector(objectParam);
	for (const auto &it : objectParam) {
		auto mapKeyValue = StringHelper::explodeString(it, ':');
		StringHelper::epureStringVector(mapKeyValue);

		if (mapKeyValue.size() != 2)
			throw ParserException("Incorect statement:\n\t" + it);
		map[mapKeyValue[0]] = mapKeyValue[1];
	}
	std::cout << "{" << std::endl;
	for (const auto &pair : map)
		std::cout << "\t" + pair.first + " : " + pair.second << std::endl;
	std::cout << "}" << std::endl;
}

void Parser::parseFile(const std::string fileName)
{
	this->loadFile(fileName);
	ssize_t i = 0;
	ssize_t j = 0;
	for (;;) {
		i = _fileContent.find_first_of("{", i);
		if (i == -1)
			break;
		j = _fileContent.find_first_of("}", i);
		if (j == -1)
			throw ParserException("Cannot find closing bracket '}'");
		std::string substr = _fileContent.substr(i + 1, j - i - 1);
		this->makeMap(substr);
		i++;
	}
}
