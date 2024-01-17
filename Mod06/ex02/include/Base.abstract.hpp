#pragma once
#ifndef BASE_ABSTRACT_HPP
# define BASE_ABSTRACT_HPP

class Base
{
	public:
		virtual ~Base();
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
