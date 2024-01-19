#include "../include/ScalarConverter.class.hpp"
#include <cmath>
#include <sstream>

static ECases impossibleCases(std::string const& str);
static ECases testIfInfinite(std::string const& str, ECases type);
static ECases testIfOverflow(std::string const& str);
static ECases validCases(std::string const& str);

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

static ECases impossibleCases(std::string const& str)
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

static ECases validCases(std::string const& str)
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

static ECases testIfOverflow(std::string const& str)
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

static ECases testIfInfinite(std::string const& str, ECases type)
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
