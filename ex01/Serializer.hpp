#pragma once

#include "Data.hpp"

#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"
#define NC "\e[0m"

#include <stdint.h>

class Serializer
{
public:
	Serializer();
	Serializer(const Serializer& original);
	Serializer &operator=(const Serializer& original);
	~Serializer();

	static uintptr_t	serializer(Data* ptr);
	static Data*		deserializer(uintptr_t raw);
};