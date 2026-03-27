#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << BRED << "Attention: Enter one argument!\n" << NC;
		return 1;
	}
	std::string str = av[1];
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isprint(str[i]))
		{
			std::cout << BRED << "Attention: Enter a printable argument!\n" << NC;
			return 1;
		}
	}

	ScalarConverter::convert(av[1]);
	return 0;
}