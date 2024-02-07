#include "../include/RPN.class.hpp"

static bool biggerThanTen(std::string& input);
static void validateInput(std::string& input) throw (std::invalid_argument);
void removeSpaces(std::string& str);
void removeWhitespaces(std::string& str);

int main(int argc, char** argv)
{
  switch (argc) {
    case 2:
      try {
        std::string input(argv[1]);

        validateInput(input);
        std::cout << RPN::calculate(input) << std::endl;
        break;
      } catch (std::invalid_argument& inv) {
        std::cout << inv.what() << std::endl;
        return (-2);
      } catch (std::domain_error& dom) {
        std::cout << dom.what() << std::endl;
        return (-3);
      } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return (-4);
      }
    default:
      std::cout << "Usage: " + std::string(argv[0]) + " RPN_expression" << std::endl;
      return (-1);
  }
  return (0);
}

static void validateInput(std::string& input)
throw (std::invalid_argument)
{
  removeWhitespaces(input);
  if (input.empty()) {
    throw std::invalid_argument("Empty input");
  } else if (input.find_first_not_of("0123456789 +-*/") != std::string::npos) {
    throw std::invalid_argument("Invalid char");
  } else if (biggerThanTen(input)) {
    throw std::invalid_argument("Number bigger than 10");
  }
  removeSpaces(input);
}

static bool biggerThanTen(std::string& input)
{
  for (std::string::iterator it = input.begin(); it != input.end(); ++it) {
    if (isdigit(static_cast<int>(*it)) && *it > '0') {
      if (it + 1 != input.end() && isdigit(static_cast<int>(*(it + 1)))) {
        return (true);
      }
    }
  }
  return (false);
}
