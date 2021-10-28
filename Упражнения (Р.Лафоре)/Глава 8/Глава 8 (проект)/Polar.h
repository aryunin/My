#pragma once

struct Cartesian
{
	double X;
	double Y;
};

class Polar
{
private:
	double radius;
	double angle;
	static const double MAX_DBL;
	static const double PI;
public:
	Polar();
	Polar(double);
	Polar(double, double);
	Polar(Cartesian); // Конструктор преобразования
	Polar operator+(Polar) const;
	Cartesian ptoc() const;
	void ctop(Cartesian);
	bool add_overflow(double, double) const;
	bool mul_overflow(double, double) const;
	void show() const;
	void DegToRad();
	double RadToDeg(double) const;
};

