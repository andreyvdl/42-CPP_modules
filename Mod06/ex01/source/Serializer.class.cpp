#include "../include/Serializer.class.hpp"

/* TRUCTORS ================================================================= */

Serializer::Serializer(void) {};

Serializer::Serializer(Serializer const& that)
{
	(void)that;
}

Serializer::~Serializer(void) {};

/* OPERATORS ================================================================ */

Serializer& Serializer::operator=(Serializer const& that)
{
	(void)that;
	return (*this);
}

/* METHODS ================================================================== */

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
