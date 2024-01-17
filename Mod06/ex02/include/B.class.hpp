#pragma once
#ifndef B_CLASS_HPP
# define B_CLASS_HPP

# include "Base.abstract.hpp"

class B: public Base {};

bool isB(Base* ptr);
bool isB(Base& ref);

#endif
