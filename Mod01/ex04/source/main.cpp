/**
 * @file main.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File for main of the Sed program.
 * @version 1
 * @date 2023-11-14
 * 
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include <fstream>
#include "Defines.hpp"
#define CRLF "\r\n"

namespace utils {
	void argNumError(std::string msg) {
		std::cout << FG_RED << "Error: " << msg << RESET << CRLF
			<< "e.g. " << FG_GREEN << "./Sed.exec " << FG_UL_RED
			<< "/your/file/path" << RESET << " " << FG_UL_RED << "searchStr"
			<< RESET << " [" << FG_UL_RED << "replaceStr" << RESET
			<< "]" << std::endl;
	}

	void bruhMoment(void) {
		std::cout << BG_BD_RED << "BRUH DO YOU WANT TO DESTROY YOUR COMPUTER?"
			<< RESET << std::endl;
	}

	void fileOpeningError(std::string type) {
		std::cout << FG_RED << "Error: Opening " << type << RESET
			<< std::endl;
	}

	void fileWhileError(std::string type) {
		std::cout << FG_RED << "Error: While " << type << " file" << RESET
			<< std::endl;
	}

	void replace(std::string& line, std::string find, std::string sub) {
		size_t idx = 0;
		size_t found = 0;

		while (true) {
			found = line.find(find, idx);
			if (found == std::string::npos)
				break;
			line.erase(found, find.size());
			line.insert(found, sub);
			idx = found + sub.size();
		}
	}

	void closeFiles(std::ifstream& input, std::ofstream& output) {
		input.close();
		output.close();
	}
}

int searchAndReplaceIt(std::string file, std::string find, std::string sub);

int main(int argC, char** argV) {
	int status = 0;

	if (argC != 4) {
		switch (argC) {
			case 1:
				utils::argNumError("No file path");
				break;
			case 2:
				utils::argNumError("No search string");
				break;
			case 3:
				utils::argNumError("No replace string");
				break;
			default:
				utils::argNumError("Too many arguments");
				break;
		}
		return (argC);
	}
	if (std::string(argV[2]) == "") {
		utils::bruhMoment();
		return (-1);
	}
	status = searchAndReplaceIt(argV[1], argV[2], argV[3]);
	return (status);
}

int searchAndReplaceIt(std::string file, std::string find, std::string sub) {
	std::ifstream input(file.c_str(), input.in);

	if (input.fail() || input.is_open() == false) {
		utils::fileOpeningError("input file");
		return (4);
	}

	std::ofstream output((file + ".replace").c_str(),
		output.out | output.trunc
	);

	if (output.fail() || output.is_open() == false) {
		utils::fileOpeningError("output file");
		input.close();
		return (5);
	}
	while (input.eof() == false) {
		std::string line;

		std::getline(input, line);
		if (input.eof() == false && input.fail()) {
			utils::fileWhileError("reading");
			utils::closeFiles(input, output);
			return (6);
		}
		utils::replace(line, find, sub);
		if (input.eof() == false)
			output << line << std::endl;
		else
			output << line;
		if (output.fail()) {
			utils::fileWhileError("writing");
			utils::closeFiles(input, output);
			return (7);
		}
	}
	utils::closeFiles(input, output);
	return (0);
}
