#include "../includes/Serializer.hpp"

Serializer::Serializer(void)
{
	return ;
}

Serializer::Serializer(const Serializer& copied)
{
	(void)copied;
	return ;
}

Serializer::~Serializer(void)
{
	return ;
}

Serializer& Serializer::operator=(const Serializer& base)
{
	(void)base;
	return *this;
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
