/**
 * @file megaphone.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief A simple program that prints the passed argument in uppercase.
 * @version 1
 * @date 2023-10-31
 * 
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include <string>

void printArgv(int argC, char** argV);

int main(int argC, char* argV[]) {
	if (argC != 1)
		printArgv(argC, argV);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}

void printArgv(int argC, char** argV) {
	std::string fullStr = "";

	for (int i = 1; i < argC; ++i) {
		std::string str = argV[i];

		for (std::string::iterator it = str.begin(); it != str.end(); ++it)
			*it = static_cast<char>(std::toupper(*it));
		fullStr += str;
	}
	std::cout << fullStr << std::endl;
}
