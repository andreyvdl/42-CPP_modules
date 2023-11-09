/**
 * @file main.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Just a main to learn the difference between PTR and REF.
 * @version 1
 * @date 2023-11-09
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef FT_COLORS
# define FT_COLORS

# define RESET "\033[0m"
# define FG_YELLOW "\033[33m"
# define BG_RED "\033[41m"
# define BG_GREEN "\033[42m"
# define BG_MAGENTA "\033[45m"
# define BG_CYAN "\033[46m"

#endif

#include <iostream>

void genericFunction(std::string str, std::string* strPTR, std::string& strREF);

int main(void) {
	std::string string = "HI THIS IS BRAIN";
	// classic pointer from C
	std::string* stringPTR = &string;
	// works as a derefrenced pointer
	std::string& stringREF = string;

	std::cout << FG_YELLOW
		<< "ADDRESSES ========================================================="
		<< RESET << std::endl;
	std::cout << "string ADDRESS:         " << BG_GREEN << &string << RESET
		<< std::endl;
	std::cout << "stringPTR hold ADDRESS: " BG_CYAN << stringPTR
		<< RESET << std::endl;
	std::cout << "stringPTR ADDRESS:      " << BG_MAGENTA << &stringPTR
		<< RESET << std::endl;
	std::cout << "stringREF hold ADDRESS: " << BG_RED << &stringREF << RESET
		<< std::endl;
	std::cout << FG_YELLOW
		<< "VALUES ============================================================"
		<< RESET << std::endl;
	std::cout << "string VALUE:           " << BG_GREEN << string << RESET
		<< std::endl;
	std::cout << "stringPTR VALUE:        " << BG_CYAN << *stringPTR << RESET
		<< std::endl;
	std::cout << "stringREF VALUE:        " << BG_RED << stringREF << RESET
		<< std::endl << std::endl;
	genericFunction(string, &string, string);
	return (0);
}

void genericFunction(std::string str, std::string* strPTR, std::string& strREF)
{
	std::cout << FG_YELLOW
		<< "ADDRESSES ========================================================="
		<< RESET << std::endl;
	std::cout << "str ADDRESS:         " << BG_GREEN << &str << RESET
		<< std::endl;
	std::cout << "strPTR hold ADDRESS: " BG_CYAN << strPTR
		<< RESET << std::endl;
	std::cout << "strPTR ADDRESS:      " << BG_MAGENTA << &strPTR
		<< RESET << std::endl;
	std::cout << "strREF hold ADDRESS: " << BG_RED << &strREF << RESET
		<< std::endl;
	std::cout << FG_YELLOW
		<< "VALUES ============================================================"
		<< RESET << std::endl;
	std::cout << "str VALUE:           " << BG_GREEN << str << RESET
		<< std::endl;
	std::cout << "strPTR VALUE:        " << BG_CYAN << *strPTR << RESET
		<< std::endl;
	std::cout << "strREF VALUE:        " << BG_RED << strREF << RESET
		<< std::endl << std::endl;
}
