#include "fraction.h"
#include <iostream>

fraction fraction::operator+(fraction ff) const
{
	int num = numerator * ff.denominator + ff.numerator * denominator;
	int den = denominator * ff.denominator;
	return fraction(num,den);
}

fraction fraction::operator-(fraction ff) const
{
	int num = numerator * ff.denominator - ff.numerator * denominator;
	int den = denominator * ff.denominator;
	return fraction(num,den);
}

fraction fraction::operator*(fraction ff) const
{
	int num = numerator * ff.numerator;
	int den = denominator * ff.denominator;
	return fraction(num,den);
}

fraction fraction::operator/(fraction ff) const
{
	int num = numerator * ff.denominator;
	int den = denominator * ff.numerator;
	return fraction(num, den);
}

bool fraction::operator==(fraction ff) const
{
	return (numerator == ff.numerator && denominator == ff.denominator) ? true : false;
}

bool fraction::operator!=(fraction ff) const
{
	return (numerator != ff.numerator || denominator != ff.denominator) ? true : false;
}

void fraction::lowterms()
{
	long gcd = 1;
	bool isNegative = false;
	bool isInverted = false;

	if (denominator == 0)
	{
		std::cout << "Недопустимый знаменатель!"; exit(1);
	}
	else if (numerator == 0)
	{
		numerator = 0; denominator = 1; return;
	}


	if (numerator < 0 && denominator > 0 || denominator < 0 && numerator > 0)
		isNegative = true;
	numerator = labs(numerator);
	denominator = labs(denominator);
	
	if (numerator < denominator)
	{
		invertion();
		isInverted = true;
	}

	if (numerator % denominator == 0)
		gcd = denominator;
	else
		for (int i = 2; i <= denominator / 2; i++)
			if (numerator % i == 0 && denominator % i == 0) gcd = i;

	if (isInverted)
		invertion();
	if (isNegative)
		numerator = -numerator;

	numerator = numerator / gcd;
	denominator = denominator / gcd;
}

void fraction::invertion()
{
	long temp;
	temp = numerator;
	numerator = denominator;
	denominator = temp;
}