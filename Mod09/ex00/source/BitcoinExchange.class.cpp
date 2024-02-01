#include "../include/BitcoinExchange.class.hpp"

static bool invalidLine(std::string const& line);

// EXCPETIONS =================================================================

const char* NoDatabaseExc::what(void) throw()
{
  return ("No database file found!");
}

const char* InvalidDatabaseExc::what(void) throw()
{
  return ("Database is wrong!");
}

const char* InvalidLineExc::what(void) throw()
{
  return ("This line isn't valid!");
}

const char* WrongDateExc::what(void) throw()
{
  return ("The date isn't valid!");
}

const char* ValueWrongExc::what(void) throw()
{
  return ("The value ins't valid!");
}

// TRUCTORS ===================================================================

BtcEx::BtcEx(void): _table(), _loaded(false) {};

BtcEx::BtcEx(BtcEx const& that): _table(), _loaded(false)
{
  *this = that;
}

BtcEx::~BtcEx(void) {};

// OPERATOR ===================================================================

BtcEx&  BtcEx::operator=(BtcEx const& that)
{
  if (this != &that) {
    _table = that._table;
    _loaded = that._loaded;
  }
  return (*this);
}

// METHODS ====================================================================

void  BtcEx::initTable(void)
throw(NoDatabaseExc, InvalidDatabaseExc)
{
  std::ifstream database("./data.csv");

  if (database.fail() || database.is_open() == false) {
    throw NoDatabaseExc();
  }

  std::string line;

  std::getline(database, line);
  removeWhitespace(line);
  if (invalidLine(line)) {
    throw InvalidDatabaseExc();
  }
  line.clear();
  while (database.eof() == false) {
    std::getline(database, line);
    removeWhitespace(line);
    if (invalidLine(line)) {
      throw InvalidDatabaseExc();
    }
    addToTable(line);
    line.clear();
  }
  database.close();
}

void  BtcEx::convert(std::string const& line)
throw(InvalidLineExc, WrongDateExc, ValueWrongExc)
{
  
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
        && valueValid(line.substr(line.find(",") + 1))
      ) {
        return (false);
      }
    }
  }
  return (true);
}
