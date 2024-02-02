#include <iostream>
#include <fstream>

static int runProgram(std::string const filename);
static int printValues(std::ifstream& file, BitcoinExchange const& db);

int main(int argc, char** argv)
{
  switch (argc) {
    case 1:
      std::cout << "Error: Missing filename!" << std::endl;
      return (-1);
    case 2:
      return (runProgram(std::string(argv[1])));
    default:
      std::cout << "Error: Too many arguments!" << std::endl;
      return (-argc);
  }
}

static int runProgram(std::string const path)
{
  std::ifstream file(path.c_str());
  
  if (file.fail() || file.is_open() == false) {
    std::cout << "Error: fail at opening file, check name and permission!"
      << std::endl;
    return (1);
  }

  BitcoinExchange database;

  try {
    database.initTable();
  } catch(std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
    file.close();
    return (2);
  }
  return (printValues(file, database));
}

static int printValues(std::ifstream& file, BitcoinExchange const& db)
{
  std::string line;

  std::getline(file, line);
  if (invalidHeader(line)) {


  while (file.eof() == false) {
    std::getline(file, line);
    try {
      db.convert(line);
    } catch (std::exception& e) {
      std::cout << "Error: " << e.what() << " => " << line << std::endl;
    }
    line.clear();
  }
  file.close();
  return (0);
}
