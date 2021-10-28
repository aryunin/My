#include "Polar.h"
#include <cmath>
#include <iostream>
#include <iomanip>

const double Polar::MAX_DBL = 999999999999990.00;
const double Polar::PI = 3.14;

Polar::Polar() : radius(0), angle(0)
{ }

Polar::Polar(double r) : radius(r), angle(0)
{ }

Polar::Polar(double r, double ang) : radius(r), angle(ang)
{
	DegToRad(); 
}

Polar::Polar(Cartesian c) // Конструктор преобразования
{
	ctop(c);
}

Polar Polar::operator+(Polar p1) const
{
	Cartesian t1 = ptoc();
	Cartesian t2 = p1.ptoc();
	if(add_overflow(t1.X, t2.X) || add_overflow(t1.Y, t2.Y))
	{
		std::cerr << "Error: overflow!\n"; exit(1);
	}
	else
	{
		Cartesian t3 = { t1.X + t2.X, t1.Y + t2.Y };
		return Polar(t3);
	}
}

Cartesian Polar::ptoc() const
{ 
	double x = radius * cos(angle);
	double y = radius * sin(angle);
	Cartesian tmp = { x, y };
	return tmp;
}

void Polar::ctop(Cartesian c)
{
	if( mul_overflow(c.X, c.X) || mul_overflow(c.Y, c.Y)
		|| add_overflow(c.X * c.X, c.Y * c.Y) )
	{
		std::cerr << "Error: overflow!\n"; exit(1);
	}
	else
	{
		radius = sqrt(c.X * c.X + c.Y * c.Y);
		if (radius != 0)
			angle = acos(c.X / radius);
		else
			angle = 0;
	}
}

bool Polar::add_overflow(double x, double y) const
{
	if (x > MAX_DBL - y)
		return true;
	else
		return false;
}

bool Polar::mul_overflow(double x, double y) const
{
	if (y != 0 && abs(x) > MAX_DBL / abs(y))
		return true;
	else
		return false;
}

void Polar::show() const
{
	std::cout << std::fixed << std::setprecision(2) << "x(" << radius << ", " << RadToDeg(angle) << ")\n";
}

void Polar::DegToRad()
{
	angle = (PI * angle) / 180.00;
}

double Polar::RadToDeg(double ang) const
{
	double tmp = (angle * 180.00) / PI;
	return tmp;
}




