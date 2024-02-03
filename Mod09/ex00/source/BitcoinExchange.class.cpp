#include "../include/BitcoinExchange.class.hpp"

static bool invalidLine(std::string const& line);
static bool valueValidTable(std::string value);

// EXCPETIONS =================================================================

const char* NoDatabaseExc::what() throw()
{
  return ("No database file found!");
}

const char* InvalidDatabaseExc::what() throw()
{
  return ("Database is wrong!");
}

const char* InvalidLineExc::what() throw()
{
  return ("This line isn't valid!");
}

const char* WrongDateExc::what() throw()
{
  return ("The date isn't valid!");
}

const char* ValueWrongExc::what() throw()
{
  return ("The value ins't valid!");
}

const char* DoubleKeyExc::what() throw()
{
  return ("Table have repeated dates!");
}

// TRUCTORS ===================================================================

BitcoinExchange::BitcoinExchange(void): _table(), _loaded(false) {};

BitcoinExchange::BitcoinExchange(BitcoinExchange const& that):
_table(), _loaded(false)
{
  *this = that;
}

BitcoinExchange::~BitcoinExchange(void) {};

// OPERATOR ===================================================================

BitcoinExchange&  BitcoinExchange::operator=(BitcoinExchange const& that)
{
  if (this != &that) {
    _table = that._table;
    _loaded = that._loaded;
  }
  return (*this);
}

// METHODS ====================================================================

void  BitcoinExchange::addToTable(std::string const& line)
throw (DoubleKeyExc)
{
  std::string key(line.substr(0, line.find(',')));
  std::string nbr(line.substr(line.find(',') + 1));
  std::istringstream iss(nbr);
  double value;

  iss >> value;

  std::pair<MAP_CALL::iterator, bool> ret;

  ret = _table.insert(std::pair<std::string, double>(key, value));
  if (ret.second == false) {
    throw DoubleKeyExc();
  }
}

void  BitcoinExchange::initTable(void)
throw(NoDatabaseExc, InvalidDatabaseExc, DoubleKeyExc)
{
  std::ifstream database("./data.csv");

  if (database.fail() || database.is_open() == false) {
    throw NoDatabaseExc();
  }

  std::string line;

  std::getline(database, line);
  removeWhitespace(line);
  if (invalidLine(line)) {
    database.close();
    throw InvalidDatabaseExc();
  }
  line.clear();
  while (database.eof() == false) {
    std::getline(database, line);
    removeWhitespace(line);
    if (invalidLine(line)) {
      database.close();
      throw InvalidDatabaseExc();
    }
    try {
      addToTable(line);
    } catch (std::exception& e) {
      database.close();
      throw e;
    }
    line.clear();
  }
  database.close();
}

void  BitcoinExchange::convert(std::string const& line)
throw(InvalidLineExc, WrongDateExc, ValueWrongExc)
{
  size_t d = line.find('|');

  if (d == std::string::npos) {
    throw InvalidLineExc();
  }

  std::string key = line.substr(0, d);
  std::string value = line.substr(d + 1);

  removeWhitespace(key);
  removeWhitespace(value);
  if (dateValid(key) == false) {
    throw WrongDateExc();
  } else if (valueValid(value) == false) {
    throw ValueWrongExc();
  }

  double dValue = atof(value.c_str());
  MAP_CALL::iterator it = _table.lower_bound(key);

  if (it == _table.end()) {
    std::cout << key << " => " << dValue << " = " << (--it)->second * dValue
      << std::endl;
  } else {
    std::cout << key << " => " << dValue << " = "
      << (it->first == key ? it->second * dValue : it == _table.begin() ?
        0 : (--it)->second * dValue
      ) << std::endl;
  }
}

// AUX ========================================================================

static bool invalidLine(std::string const& line)
{
  static bool checkHeader = true;

  if (checkHeader) {
    if (line == "date,exchange_rate") {
      checkHeader = !checkHeader;
      return (false);
    }
  } else {
    if (line.find(",") != std::string::npos) {
      if (dateValid(line.substr(0, line.find(",")))
        && valueValidTable(line.substr(line.find(",") + 1))
      ) {
        return (false);
      }
    }
  }
  return (true);
}

static bool valueValidTable(std::string value)
{
  bool period = false;

  for (std::string::iterator it = value.begin(); it != value.end(); ++it) {
    if (static_cast<char>(*it) == '.' && period == false) {
      period = !period;
      continue;
    } else if (isdigit(static_cast<int>(*it)) == 0) {
      return (false);
    }
  }

  std::istringstream iss(value);
  double nbr;

  iss.exceptions(std::ios::failbit);
  try {
    iss >> nbr;
  } catch (std::exception& e) {
    static_cast<void>(e);
    return (false);
  }
  return (true);
}
