#include "../include/Serializer.class.hpp"
#include "../include/Data.class.hpp"

int main(void)
{
	//Serializer serial;
	Data* data = new Data();
	uintptr_t raw = Serializer::serialize(data);
	Data* copy = Serializer::deserialize(raw);

	std::cout << "data->getPrivate(): " << data->getPrivate() << std::endl;
	// raw = -42; result in a segfault
	std::cout << "copy->getPrivate(): " << copy->getPrivate() << std::endl;

	delete data;
	return (0);
}
