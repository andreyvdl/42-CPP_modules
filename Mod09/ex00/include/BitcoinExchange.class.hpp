#pragma once
#ifndef BITCOIN_EXCHANGE_CLASS_HPP
# define BITCOIN_EXCHANGE_CLASS_HPP

# include <algorithm>
# include <cstdlib>
# include <fstream>
# include <iostream>
# include <map>
# include <sstream>
# include <stdexcept>

# define MAP_CALL std::map<std::string, double>

bool dateValid(std::string date);
void removeWhitespace(std::string& line);

class NoDatabaseExc: public std::exception
{
  public:
    virtual const char* what() const throw();
};

class InvalidDatabaseExc: public std::exception
{
  public:
    virtual const char* what() const throw();
};

class InvalidLineExc: public std::exception
{
  public:
    virtual const char* what() const throw();
};

class WrongDateExc: public std::exception
{
  public:
    virtual const char* what() const throw();
};

class ValueWrongExc: public std::exception
{
  public:
    virtual const char* what() const throw();
};

class DoubleKeyExc: public std::exception
{
  public:
    virtual const char* what() const throw();
};

class BitcoinExchange
{
  private:
    MAP_CALL  _table;
    bool      _loaded;

    void  addToTable(std::string const& line) throw (DoubleKeyExc);

  public:
    BitcoinExchange(void);
    BitcoinExchange(BitcoinExchange const& that);
    ~BitcoinExchange(void);

    BitcoinExchange&  operator=(BitcoinExchange const& that);

    void  initTable(void)
      throw(NoDatabaseExc, InvalidDatabaseExc, DoubleKeyExc);
    void  convert(std::string const& line)
      throw(InvalidLineExc, WrongDateExc, ValueWrongExc); 
};

#endif
