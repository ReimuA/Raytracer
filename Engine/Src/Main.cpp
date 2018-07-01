/*
** Raytracer by ReimuA
*/

#include <string>
#include <iostream>
#include <stdexcept>
#include "IObject.hpp"
#include "Parser.hpp"

int main(int argc, char **argv)
{
	try {
		if (argc != 2)
			return 1;
		Parser parser;
		parser.parseFile(std::string(argv[1]));
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
