#include "../include/ScalarConverter.class.hpp"
#include <sstream>
#include <iostream>
#include <cmath>

ECases impossibleCases(std::string const& str);
ECases detectType(std::string const& str);
ECases testIfInfinite(std::string const& str, ECases type);
ECases testIfOverflow(std::string const& str);
ECases validCases(std::string const& str);
void printImpossibility(void);
void printNan(void);
void printInf(ECases type);
void printChar(std::string const& str);
void printFloating(std::string const& str);
void printInteger(std::string const& str);

/* TRUCTORS ================================================================= */

ScalarConverter::ScalarConverter(void) {};

ScalarConverter::ScalarConverter(ScalarConverter const& that)
{
	*this = that;
}

ScalarConverter::~ScalarConverter(void) {};

/* OPERATORS ================================================================ */

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& that)
{
	(void)that;
	return (*this);
}

/* METHODS ================================================================== */

void ScalarConverter::convert(std::string const& str)
{
	size_t start = str.find_first_not_of(" \t");
	size_t end = str.find_last_not_of(" \t");

	if (start != std::string::npos && end != std::string::npos) {
		const_cast<std::string&>(str) = str.substr(start, end - start + 1);
	} else if (start != std::string::npos) {
		const_cast<std::string&>(str) = str.substr(start);
	} else if (end != std::string::npos) {
		const_cast<std::string&>(str) = str.substr(0, end + 1);
	}

	ECases type = detectType(str);
	switch (type) {
		case MEGA_IMPOSSIBLE:
			printImpossibility();
			break;
		case E_NAN:
			printNan();
			break;
		case NEG_INF:
		case POS_INF:
			printInf(type);
			break;
		case DOUBLE:
		case FLOAT:
			printFloating(str);
			break;
		case INT:
			printInteger(str);
			break;
		case CHAR:
			printChar(str);
			break;
	}
}

ECases detectType(std::string const& str)
{
	switch (impossibleCases(str)) {
		case E_NAN:
			return (E_NAN);
		case NEG_INF:
			return (NEG_INF);
		case POS_INF:
			return (POS_INF);
		default:
			break;
	}
	switch (validCases(str)) {
		case CHAR:
			return (CHAR);
		case INT:
			return (INT);
		case FLOAT:
			return (FLOAT);
		case DOUBLE:
			return (DOUBLE);
		case NEG_INF:
			return (NEG_INF);
		case POS_INF:
			return (POS_INF);
		default:
			break;
	}
	return (MEGA_IMPOSSIBLE);
}

ECases impossibleCases(std::string const& str)
{
	ECases eArr[8] = {E_NAN, E_NAN, NEG_INF, NEG_INF, POS_INF, POS_INF,
		POS_INF, POS_INF
	};
	std::string strArr[8] = {"nan", "nanf", "-inf", "-inff", "+inf", "+inff",
		"inf", "inff"
	};

	for (int i = 0; i < 8; i++) {
		if (str == strArr[i])
			return (eArr[i]);
	}
	return (MEGA_IMPOSSIBLE);
}

ECases validCases(std::string const& str)
{
	if (str.size() == 1 && !isdigit(str[0])) {
		return (CHAR);
	} else if (str.find_first_of(".") == std::string::npos) {
		return (testIfOverflow(str));
	} else if (str.find_first_of("f") != std::string::npos) {
		return (testIfInfinite(str, FLOAT));
	} else if (str.find_first_of(".") != std::string::npos) {
		return (testIfInfinite(str, DOUBLE));
	}
	return (MEGA_IMPOSSIBLE);
}

ECases testIfOverflow(std::string const& str)
{
	std::istringstream iss(str);
	int num = 0;

	iss.exceptions(std::ios::failbit);
	try {
		iss >> num;
	} catch (std::exception& e) {
		(void)e;
		return (MEGA_IMPOSSIBLE);
	}
	return (INT);
}

ECases testIfInfinite(std::string const& str, ECases type)
{
	std::istringstream iss(str);
	float fNum = static_cast<float>(0);
	double dNum = static_cast<double>(0);

	iss.exceptions(std::ios::failbit);
	switch (type) {
		case FLOAT:
			try {
				iss >> fNum;
				if (std::isinf(fNum)) {
					return (fNum < 0 ? NEG_INF : POS_INF);
				}
				return (FLOAT);
			} catch (std::exception& e) {
				(void)e;
				return (MEGA_IMPOSSIBLE);
			}
		case DOUBLE:
			try {
				iss >> dNum;
				if (std::isinf(dNum)) {
					return (dNum < 0 ? NEG_INF : POS_INF);
				}
				return (DOUBLE);
			} catch (std::exception& e) {
				(void)e;
				return (MEGA_IMPOSSIBLE);
			}
		default:
			return (MEGA_IMPOSSIBLE);
	}
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
	std::string printableChar(isprint(static_cast<int>(dNum)) ?
		std::string(1, static_cast<char>(dNum)) : "Non displayable");

	std::cout << "char: " << printableChar << std::endl
		<< "int: " << static_cast<int>(dNum) << std::endl
		<< "float: " << static_cast<float>(dNum) << "f" << std::endl
		<< "double: " << dNum << std::endl;
}

void printInteger(std::string const& str)
{
	int iNum = 0;

	iNum = atoi(str.c_str());
	std::string printableChar(isprint(iNum) ?
		std::string(1, static_cast<char>(iNum)) : "Non displayable");

	std::cout << "char: " << printableChar << std::endl
		<< "int: " << iNum << std::endl
		<< "float: " << static_cast<float>(iNum) << "f" << std::endl
		<< "double: " << static_cast<double>(iNum) << std::endl;
}

void printChar(std::string const& str)
{
	std::string printableChar(isprint(static_cast<int>(str[0])) ?
		std::string(1, str[0]) : "Non displayable");

	std::cout << "char: " << printableChar << std::endl
		<< "int: " << static_cast<int>(str[0]) << std::endl
		<< "float: " << static_cast<float>(str[0]) << "f" << std::endl
		<< "double: " << static_cast<double>(str[0]) << std::endl;
}
