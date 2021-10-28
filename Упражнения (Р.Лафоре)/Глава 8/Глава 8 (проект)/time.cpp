#include "time.h"

time time::operator+(time t2) const
{
	int h = hrs + t2.hrs;
	int m = mins + t2.mins;
	int s = secs + t2.secs;
	return time(h, m, s);
}

time time::operator-(time t2) const
{
	int h = hrs - t2.hrs;
	int m = mins - t2.mins;
	int s = secs - t2.secs;
	return time(h, m, s);
}

time time::operator*(float k) const
{
	float s = static_cast<float>(secs + mins * 60 + hrs * 3600);
	float r = s * k;
	return time(r);
}

time time::operator++()
{ 
	++secs; time_to_std();
	return *this;
}

time time::operator++(int)
{ 
	time temp(hrs, mins, secs);
	secs++; time_to_std(); 
	return temp; 
}

time time::operator--()
{
	--secs; time_to_std();
	return *this;
}

time time::operator--(int)
{
	time temp(hrs, mins, secs);
	secs--; time_to_std();
	return temp;
}

void time::time_to_std()
{
	if (secs >= 60)
	{
		secs -= 60;
		mins++;
	}
	else if (secs < 0)
	{
		secs += 60;
		mins--;
	}

	if (mins >= 60)
	{
		mins -= 60;
		hrs++;
	}
	else if (mins < 0)
	{
		mins += 60;
		hrs--;
	}

	if (hrs < 0)
	{
		std::cerr << "Error: the resulting value is below the minimum!\n";
		exit(4);
	}
}

void time::time_to_std(float fsecs)
{
	// Округление
	int isecs = static_cast<int>(fsecs * 10);
	if (isecs % 10 >= 5)
	{
		isecs /= 10;
		isecs++;
	}
	else
		isecs /= 10;
	// Приведение к стандартному виду
	hrs = isecs / 3600;
	isecs = isecs % 3600;
	mins = isecs / 60;
	isecs = isecs % 60;
	secs = isecs;
}