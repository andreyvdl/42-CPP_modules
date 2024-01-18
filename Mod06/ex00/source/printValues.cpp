#include "../include/ScalarConverter.class.hpp"
#include <sstream>
#include <string>
#include <limits>
#include <cmath>

static std::string abstractionFloat(double dNum, std::string const& rest)
{
	std::ostringstream oss;

	if (isinff(static_cast<float>(dNum))) {
		return (std::string("impossible"));
	}
	oss << static_cast<float>(dNum) << rest + "f";
	return (oss.str());
}

static std::string abstractionInt(double dNum)
{
	std::ostringstream oss;

	if (dNum < static_cast<double>(std::numeric_limits<int>::min()) ||
		dNum > static_cast<double>(std::numeric_limits<int>::max())
	) {
		return (std::string("impossible"));
	}
	oss << static_cast<int>(dNum);
	return (oss.str());
}

static std::string abstractionChar(double dNum)
{
	return (static_cast<int>(dNum) >= 32 && static_cast<int>(dNum) <= 126 ?
		std::string("''").insert(1, 1, static_cast<char>(dNum)) :
		static_cast<int>(dNum) < 0 || static_cast<int>(dNum) > 127 ?
			std::string("impossible") :
			std::string("Non displayable")
	);
}

static std::string abstractionChar(int iNum)
{
	return (iNum >= 32 && iNum <= 126 ?
		std::string("''").insert(1, 1, static_cast<char>(iNum)) :
		iNum < 0 || iNum > 127 ?
			std::string("impossible") :
			std::string("Non displayable")
	);
}

static std::string abstractionChar(char byte)
{
	return (byte >= ' ' && byte <= '~' ?
		std::string("''").insert(1, 1, byte) :
		std::string("Non displayable")
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
	std::string intValue(abstractionInt(dNum));
	std::string floatValue(abstractionFloat(dNum, hasRemainder));

	std::cout << "char: " << charValue << std::endl
		<< "int: " << intValue << std::endl
		<< "float: " << floatValue << std::endl
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
