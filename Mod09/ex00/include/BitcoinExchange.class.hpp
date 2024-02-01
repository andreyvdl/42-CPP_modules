#pragma once
#ifndef BITCOIN_EXCHANGE_CLASS_HPP
# define BITCOIN_EXCHANGE_CLASS_HPP

# include <algorithm>
# include <fstream>
# include <iostream>
# include <map>
# include <stdexcept>

# define MAP_CALL std::map<size_t, double>

void removeWhitespace(std::string& line);

class NoDatabaseExc: public std::exception
{
  public:
    virtual const char* what() throw();
};

class InvalidDatabaseExc: public std::exception
{
  public:
    virtual const char* what() throw();
};

class InvalidLineExc: public std::exception
{
  public:
    virtual const char* what() throw();
};

class WrongDateExc: public std::exception
{
  public:
    virtual const char* what() throw();
};

class ValueWrongExc: public std::exception
{
  public:
    virtual const char* what() throw();
};


class BtcEx
{
  private:
    MAP_CALL  _table;
    bool      _loaded;

    void  addToTable(std::string const& line);

  public:
    BtcEx(void);
    BtcEx(BtcEx const& that);
    ~BtcEx(void);

    BtcEx&  operator=(BtcEx const& that);

    void  initTable(void) throw(NoDatabaseExc, InvalidDatabaseExc);
    void  convert(std::string const& line)
      throw(InvalidLineExc, WrongDateExc, ValueWrongExc); 
};

#endif
