#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& original)
{
	(void)original;
}

Serializer &Serializer::operator=(const Serializer& original)
{
	(void)original;
	return *this;
}

Serializer::~Serializer() {}

uintptr_t	Serializer::serializer(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserializer(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}