#include "../include/Data.class.hpp"

/* TRUCTORS ================================================================= */

Data::Data(void): _member(42) {};

Data::Data(Data const& that): _member(that._member) {};

Data::~Data(void) {};

/* OPERATORS ================================================================ */

Data& Data::operator=(Data const& that)
{
	_member = that._member;
	return (*this);
}

/* MEHTODS ================================================================== */

uint32_t Data::getMember(void) const
{
	return (_member);
}
