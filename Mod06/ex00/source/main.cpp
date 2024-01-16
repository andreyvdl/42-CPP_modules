#include "../include/ScalarConverter.class.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "HEY! lookout with the args, the dev is tired"
			<< std::endl;
		return (-1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
