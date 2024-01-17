#pragma once
#ifndef A_CLASS_HPP
# define A_CLASS_HPP

# include "Base.abstract.hpp"

class A: public Base {};

bool isA(Base* ptr);
bool isA(Base& ref);

#endif
