#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "usage: ./convert [input]" << std::endl;
		return 1;
	}
	ScalarConverter::convert(av[1]);
}
