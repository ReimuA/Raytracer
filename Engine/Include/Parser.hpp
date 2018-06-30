/*
** Raytracer by ReimuA
*/

#pragma once

#include <map>
#include <string>
#include <stdexcept>

class ParserException : public std::exception {
	std::string _msg;
public:
	ParserException(const std::string &msg) : _msg(msg) {};
	virtual const char *what() const noexcept {
    		return _msg.c_str();
    	}
};

class Parser {
	std::string _fileContent;

	void makeMap(const std::string &str);
	void loadFile(const std::string &fileName);
public:
	Parser();
	~Parser();
	void parseFile(const std::string fileName);
};
