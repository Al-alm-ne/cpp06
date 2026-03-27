#include "ScalarConverter.hpp"
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& original)
{
	*this = original;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& original)
{
	if (this == &original)
		return *this;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

static bool	isInt(const std::string& lit)
{
	size_t i = 0;

	if (lit[i] == '+' || lit[i] == '-')
		i++;
	if (lit.length() <= i || !std::isdigit(lit[i]))
		return false;
	if (lit[i] == '0' && lit.length() > i + 1)
		return false;
	while (i < lit.length())
	{
		if (!std::isdigit(lit[i]))
			return false;
		i++;
	}
	return true;
}

static bool isChar(const std::string& lit)
{
	if (lit.length() == 1 && !std::isdigit(lit[0]))
		return true;
	return false;
}

static bool isFloat(const std::string& lit)
{
	size_t i = 0;
	int count = 0;
	size_t l = lit.length();

	for (size_t j = 0; j < l; j++)
	{
		if (lit[j] == '.')
			count++;
	}
	if (lit[l - 1] != 'f' || count != 1 || l < 4)
		return false;
	if (lit[i] == '+' || lit[i] == '-')
		i++;
	if (l <= i || !std::isdigit(lit[i]) || lit[l - 2] == '.')
		return false;
	if (lit[i] == '0' && l > i + 1)
	{
		if (lit[i + 1] != '.')
			return false;
	}
	for (size_t j = 1; j < l - 2; j++)
	{
		if (!isdigit(lit[j]) && lit[j] != '.')
			return false;
	}
	return true;
}

static bool	isDouble(const std::string& lit)
{
	size_t i = 0;
	int count = 0;
	size_t l = lit.length();

	for (size_t j = 0; j < l; j++)
	{
		if (lit[j] == '.')
			count++;
	}
	if (count != 1 || l < 3)
		return false;
	if (lit[i] == '+' || lit[i] == '-')
		i++;
	if (l <= i || !std::isdigit(lit[i]) || lit[l - 1] == '.')
		return false;
	if (lit[i] == '0' && l > i + 1)
	{
		if (lit[i + 1] != '.')
			return false;
	}
	for (size_t j = 1; j < l - 1; j++)
	{
		if (!isdigit(lit[j]) && lit[j] != '.')
			return false;
	}
	return true;
}

bool isPseudo(const std::string& lit)
{
	if (lit == "inf" || lit == "+inf" || lit == "-inf" || lit == "nan" || lit == "inff" || lit == "-inff" || lit == "+inff" || lit == "nanf")
		return true;
	return false;
}

void	ScalarConverter::convert(const std::string &literal)
{
	if (isInt(literal) || isFloat(literal) || isDouble(literal) || isPseudo(literal))
	{
		double res = std::strtod(literal.c_str(), NULL);
		if (res < 0 || res > 127 || std::isnan(res))
			std::cout << "char: impossible\n";
		else if (std::isprint(static_cast<char>(res)))
			std::cout << "char: '" << static_cast<char>(res) << "'\n";
		else
			std::cout << "char: Non displayable\n";
		
		if (res > INT_MAX || res < INT_MIN || std::isnan(res))
			std::cout << "int: impossible\n";
		else
			std::cout << "int: " << static_cast<int>(res) << "\n";

		if (res != static_cast<int>(res))
		{
			std::cout << "float: " << static_cast<float>(res) << "f\n";
			std::cout << "double: " << static_cast<double>(res) << "\n";
		}
		else
		{
			std::cout << "float: " << static_cast<float>(res) << ".0f\n";
			std::cout << "double: " << static_cast<double>(res) << ".0\n";
		}
	}
	else if (isChar(literal))
	{
		if(std::isprint(literal[0]))
			std::cout << "char: '" << static_cast<char>(literal[0]) << "'\n";
		else
			std::cout << "char: Non displayable\n";
		std::cout	<< "int: " << static_cast<int>(literal[0]) << "\n"
					<< "float: " << static_cast<float>(literal[0]) << ".0f\n"
					<< "double: " << static_cast<double>(literal[0]) << ".0\n";
	}
	else
		std::cout << BRED << "Unknown Scalar\n" << NC;
}