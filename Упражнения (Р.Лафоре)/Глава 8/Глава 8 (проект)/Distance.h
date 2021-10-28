#pragma once
#include <iostream>
class Distance // класс английских мер длины
{
private:
	int feet;
	float inches;
public:
	// конструктор без параметров
	Distance() : feet(0), inches(0.0)
	{ }
	// конструктор с двум€ параметрами
	Distance(int ft, float in) : feet(ft), inches(in)
	{ }
	// получение информации от пользовател€
	void getdist()
	{
		std::cout << "\n¬ведите футы: "; std::cin >> feet;
		std::cout << "¬ведите дюймы: "; std::cin >> inches;
	}
	// показ информации
	void showdist()
	{
		std::cout << feet << "\'-" << inches << '\"';
	}
	// сложение двух длин
	Distance operator+(Distance) const;
	Distance operator-(Distance) const;
};