#pragma once
#ifndef C_CLASS_HPP
# define C_CLASS_HPP

# include "Base.abstract.hpp"

class C: public Base {};

bool isC(Base* ptr);
bool isC(Base& ref);

#endif
