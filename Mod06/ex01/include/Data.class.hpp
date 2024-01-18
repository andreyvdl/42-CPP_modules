#pragma once
#ifndef DATA_CLASS_HPP
# define DATA_CLASS_HPP

# include <stdint.h>

class Data
{
	private:
		uint32_t _member;

	public:
		Data(void);
		Data(Data const& that);
		~Data(void);
		Data& operator=(Data const& that);

		uint32_t getMember(void) const;
};

#endif
