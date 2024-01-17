#pragma once
#ifndef SERIALIZER_CLASS_HPP
# define SERIALIZER_CLASS_HPP

# include "Data.class.hpp"
# include <iostream>
# include <stdint.h>

class Serializer
{
	private:
		Serializer(void);
		Serializer(Serializer const& that);
		~Serializer(void);
		Serializer& operator=(Serializer const& that);

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
