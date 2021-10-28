#include "sterling.h"
#include "bMoney.h"
#include <cmath>
#include <iostream>
#include <Windows.h>

const unsigned char sterling::poundsymbol = 163;
const unsigned char sterling::pointsymbol = 46;
const double sterling::MAX_DBL = 21474836.00;
const double sterling::dollar_exRate = 50; // Цена в долларах за 1 фунт стерлингов в старом формате

sterling::sterling() : pounds(0), shillings(0), pense(0)
{ }

sterling::sterling(long pnd, int sh, int pnc) : pounds(pnd), shillings(sh), pense(pnc)
{ 
	toStandart();
}

sterling::sterling(double pnd) : pounds(0), shillings(0), pense(static_cast<int>(round(pnd * 100)))
{
	toStandart();
}

sterling::sterling(bMoney m2) : pounds(0), shillings(0)
{
	if (long double(m2) > long double(MAX_DBL))
	{
		SetConsoleOutputCP(1251);
		std::cerr << "Ошибка: переполнение!\n";
		exit(3);
	}
	else
	{
		double dbl_pense = round(static_cast<double>(m2) / (dollar_exRate / 2.4) * 100.0); // dollar_exRate / 2.4 - это цена в долларах за 1 десятичный фунт (фунт в новом формате)
		pense = static_cast<int>(dbl_pense);
		toStandart();
	}

}

void sterling::toStandart()
{
	if (pense >= 12)
	{
		shillings += pense / 12;
		pense %= 12;
	}
	else if (pense < 0)
	{
		shillings -= abs(pense) / 12 + 1;
		pense = 12 - abs(pense) % 12;
	}

	if (shillings >= 20)
	{
		pounds += shillings / 20;
		shillings %= 20;
	}
	else if (shillings < 0)
	{
		pounds -= abs(shillings) / 20 + 1;
		shillings = 20 - abs(shillings) % 20;
	}

	if (pounds < 0)
	{
		SetConsoleOutputCP(1251);
		std::cerr << "Ошибка: попытка представить отрицательную сумму!\n";
		exit(2);
	}
}

/*sterling sterling::toStandart(sterling s) const
{
	if (s.pense >= 12)
	{
		s.shillings += pense / 12;
		s.pense %= 12;
	}
	else if (s.pense < 0)
	{
		s.shillings -= abs(s.pense) / 12 + 1;
		s.pense = 12 - abs(s.pense) % 12;
	}
	if (s.shillings >= 20)
	{
		s.pounds += s.shillings / 20;
		s.shillings %= 20;
	}
	else if (s.shillings < 0)
	{
		s.pounds -= abs(s.shillings) / 20 + 1;
		s.shillings = 20 - abs(s.shillings) % 20;
	}
	if (s.pounds < 0)
	{
		SetConsoleOutputCP(1251);
		std::cerr << "Ошибка: попытка представить отрицательную сумму!\n";
		exit(2);
	}
	return s;
}*/

void sterling::putSterling() 
{
	SetConsoleCP(1252);
	unsigned char moneychar;
	unsigned char dch1, dch2;
	std::cin >> moneychar >> pounds >> dch1 >> shillings >> dch2 >> pense;
	SetConsoleCP(866);
	if (moneychar != poundsymbol || dch1 != pointsymbol || dch2 != pointsymbol)
	{
		SetConsoleOutputCP(1251);
		std::cerr << "Ошибка: неверный формат ввода!\n";
		exit(1);
	}
	else
	{
		toStandart();
	}
}

void sterling::getSterling() const
{
	SetConsoleOutputCP(1252);
	std::cout << poundsymbol << pounds << pointsymbol << shillings << pointsymbol << pense << std::endl;
	SetConsoleOutputCP(866);
}

sterling::operator double() const
{
	double decPounds = round(double(pounds) * 20.0 * 12.0 + double(shillings) * 12.0 + double(pense)) / 100.0;
	return decPounds;
}

sterling sterling::operator+(sterling s2)
{
	if (double(sterling(pounds, shillings, pense)) > MAX_DBL - double(s2))
	{
		SetConsoleOutputCP(1251);
		std::cerr << "Ошибка: переполнение!\n";
		exit(3);
	}
	else 
		return sterling(double(sterling(pounds, shillings, pense)) + double(s2));
}

sterling sterling::operator-(sterling s2)
{
	return sterling(double(sterling(pounds, shillings, pense)) - double(s2));
}

sterling sterling::operator*(double k)
{
	if (double(sterling(pounds, shillings, pense)) > MAX_DBL / k)
	{
		SetConsoleOutputCP(1251);
		std::cerr << "Ошибка: переполнение!\n";
		exit(3);
	}
	else 
		return sterling(double(sterling(pounds, shillings, pense)) * k);
}

sterling sterling::operator/(double k)
{
	if (k < 1 && k != 0 && double(sterling(pounds, shillings, pense)) > MAX_DBL * k)
	{
		SetConsoleOutputCP(1251);
		std::cerr << "Ошибка: переполнение!\n";
		exit(3);
	}
	return sterling(double(sterling(pounds, shillings, pense)) / k);
}

sterling sterling::operator/(sterling s2)
{
	double k = double(s2);
	if (k < 1 && k != 0 && double(sterling(pounds, shillings, pense)) > MAX_DBL * k)
	{
		SetConsoleOutputCP(1251);
		std::cerr << "Ошибка: переполнение!\n";
		exit(3);
	}
	return sterling(double(sterling(pounds, shillings, pense)) / k);
}
