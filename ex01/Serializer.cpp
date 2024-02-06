//
// Created by pgoua on 06/02/2024.
//

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(Serializer &obj)
{
	if (this != &obj)
		*this = obj;
}

Serializer &Serializer::operator=(Serializer &obj)
{
	(void)obj;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}