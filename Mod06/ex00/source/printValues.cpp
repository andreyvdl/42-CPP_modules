#include "../include/ScalarConverter.class.hpp"
#include <cmath>

std::string abstractionChar(double dNum)
{
	return (static_cast<int>(dNum) >= 32 && static_cast<int>(dNum) <= 126 ?
		std::string("''").insert(1, 1, static_cast<char>(dNum)) :
		"Non displayable"
	);
}

std::string abstractionChar(int iNum)
{
	return (iNum >= 32 && iNum <= 126 ?
		std::string("''").insert(1, 1, static_cast<char>(iNum)) :
		"Non displayable"
	);
}

std::string abstractionChar(char byte)
{
	return (byte >= ' ' && byte <= '~' ?
		std::string("''").insert(1, 1, byte) :
		"Non displayable"
	);
}

void printImpossibility(void)
{
	std::cout << "char: impossible" << std::endl
		<< "int: impossible" << std::endl
		<< "float: impossible" << std::endl
		<< "double: impossible" << std::endl;
}

void printNan(void)
{
	std::cout << "char: impossible" << std::endl
		<< "int: impossible" << std::endl
		<< "float: nanf" << std::endl
		<< "double: nan" << std::endl;
}

void printInf(ECases type)
{
	std::cout << "char: impossible" << std::endl
		<< "int: impossible" << std::endl
		<< "float: " << (type == NEG_INF ? "-inff" : "+inff") << std::endl
		<< "double: " << (type == NEG_INF ? "-inf" : "+inf") << std::endl;
}

void printFloating(std::string const& str)
{
	double dNum = static_cast<double>(0);

	dNum = atof(str.c_str());

	std::string charValue(abstractionChar(dNum));
	std::string hasRemainder(fmod(dNum, 1) == 0.0 ? ".0" : ""); 

	std::cout << "char: " << charValue << std::endl
		<< "int: " << static_cast<int>(dNum) << std::endl
		<< "float: " << static_cast<float>(dNum) << hasRemainder + "f"
			<< std::endl
		<< "double: " << dNum << hasRemainder << std::endl;
}

void printInteger(std::string const& str)
{
	int iNum = 0;

	iNum = atoi(str.c_str());

	std::string charValue(abstractionChar(iNum));

	std::cout << "char: " << charValue << std::endl
		<< "int: " << iNum << std::endl
		<< "float: " << static_cast<float>(iNum) << ".0f" << std::endl
		<< "double: " << static_cast<double>(iNum) << ".0" << std::endl;
}

void printChar(std::string const& str)
{
	std::string charValue(abstractionChar(str[0]));

	std::cout << "char: " << charValue << std::endl
		<< "int: " << static_cast<int>(str[0]) << std::endl
		<< "float: " << static_cast<float>(str[0]) << ".0f" << std::endl
		<< "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
}
