#pragma once
#ifndef SCALAR_CONVERTER_CLASS_HPP
# define SCALAR_CONVERTER_CLASS_HPP

# include <iostream>

enum ECases
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NEG_INF,
	POS_INF,
	E_NAN,
	MEGA_IMPOSSIBLE
};

class ScalarConverter
{
	// se o contrutor for privado a classe n pode ser instanciada
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const& that);
		~ScalarConverter(void);
		ScalarConverter& operator=(ScalarConverter const& that);

	public:
		static void convert(std::string const& str);
};

#endif
