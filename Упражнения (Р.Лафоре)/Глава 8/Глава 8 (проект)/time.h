#pragma once
#include <iostream>
class time
{
private:
	int hrs, mins, secs;
public:
	time() : hrs(0), mins(0), secs(0)
	{ }
	time(int _hrs, int _mins, int _secs) : hrs(_hrs), mins(_mins), secs(_secs)
	{
		time_to_std();
	}
	time(float _secs) : hrs(0), mins(0), secs(0)
	{
		time_to_std(_secs);
	}
	void show() const
	{
		std::cout << hrs << ':' << mins << ':' << secs << std::endl;
	}
	time operator+(time) const;
	time operator-(time) const;
	time operator*(float) const;
	time operator++();
	time operator++(int);
	time operator--();
	time operator--(int);
	void time_to_std();
	void time_to_std(float);
};