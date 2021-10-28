#pragma once
#include <iostream>

class fraction
{
private:
	long numerator;
	long denominator;
public:
	fraction() : numerator(1), denominator(1)
	{ }
	fraction(long num) : numerator(num), denominator(1)
	{ }
	fraction(long num, long den) : numerator(num), denominator(den)
	{
		lowterms();
	}
	void getFract()
	{
		char dummychar;
		std::cin >> numerator >> dummychar >> denominator;
	}
	void lowterms();
	void showFract() const
	{
		std::cout << numerator << '/' << denominator;
	}
	fraction operator+(fraction) const;
	fraction operator-(fraction) const;
	fraction operator*(fraction) const;
	fraction operator/(fraction) const;
	bool operator==(fraction) const;
	bool operator!=(fraction) const;
	void invertion();
};
