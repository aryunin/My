#pragma once
#include <iostream>

class Int
{
private:
	int value;
public:
	Int() : value(0)
	{ }
	Int(int _value) : value(_value)
	{ }
	void showint() const
	{
		std::cout << value << std::endl;
	}
	Int operator-();
	Int operator+();
	Int operator+(Int) const;
	Int operator-(Int) const;
	Int operator*(Int) const;
	Int operator/(Int) const;
};
