#include "Int.h"

Int Int::operator-()
{
	if (value == INT_MIN)
	{
		std::cerr << "Error: overflow!\n";
		exit(3);
	}
	else 
		return Int(-value);
}

Int Int::operator+()
{
	return Int(+value);
}

Int Int::operator+(Int v2) const
{
	bool c1 = value > 0 && v2.value > INT_MAX - value; // Переполнение в положительную сторону
	bool c2 = value < 0 && v2.value < INT_MIN - value; // Переполнение в отрицательную сторону
	if (value != 0 && (c1 || c2))
	{
		std::cerr << "Error: overflow!\n";
		exit(1);
	}
	else
	{
		int result = value + v2.value;
		return Int(result);
	}
}

Int Int::operator-(Int v2) const
{
	return operator+(-v2);
	/*bool c1 = value > 0 && v2.value < value - INT_MAX;
	bool c2 = value < 0 && v2.value > value - INT_MIN;
	if (value != 0 && (c1 || c2))
	{
		std::cerr << "Error: overflow!\n";
		exit(1);
	}
	else
	{
		int result = value + (-v2.value);
		return Int(result);
	}*/
}

Int Int::operator*(Int v2) const
{
	if(value != 0 && abs(v2.value) > INT_MAX / abs(value))
	{
		std::cerr << "Error: overflow!\n";
		exit(1);
	}
	else
	{
		int result = value * v2.value;
		return Int(result);
	}
}

Int Int::operator/(Int v2) const
{
	if (v2.value == 0)
	{
		std::cerr << "Error: division by zero!\n";
		exit(2);
	}
	else
	{
		int result = value / v2.value;
		return Int(result);
	}
}