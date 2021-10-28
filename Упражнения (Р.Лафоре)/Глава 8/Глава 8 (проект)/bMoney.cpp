#include "bMoney.h"
#include "sterling.h"
#include <iostream>
#include <sstream>
#include <iomanip>


const long double bMoney::MAX_LDBL_USR = 999999999999990.00;
const double bMoney::sterling_exRate = 0.02; // Цена в фунтах стерлингах (в старом формате) одного доллара

bMoney::bMoney() : money(0)
{ }

bMoney::bMoney(std::string s)
{
	money = mstold(s);
}

bMoney::bMoney(sterling s) // Конструктор преобразования
{
	money = round(double(s) / (sterling_exRate * 2.4) * 100) / 100; // 2.4 десятичных фунта стерлингов = 1 фунт стерлингов старого формата
}

bMoney::bMoney(long double m) : money(m) 
{ }

void bMoney::getMoney()
{
	std::string strout = ldtoms(money);
	std::cout << strout;
}

void bMoney::putMoney()
{
	std::string strin;
	std::cin >> strin;
	money = mstold(strin);
}

long double bMoney::mstold(std::string sin)
{
	std::string available = "-0123456789."; // символы, которые не будут игнорироваться при преобразовании
	std::stringstream ss;
	// исключение лишних символов
	for (int i = 0; i < sin.size(); i++)
		if (available.find(sin.at(i)) != -1)
			ss << sin.at(i);
	// преобразование в long double
	long double tmp;
	ss >> std::fixed >> std::setprecision(2) >> tmp;
	if (tmp > MAX_LDBL_USR)
	{
		std::cerr << "Error: overflow!\n";
		exit(1);
	}
	else if (tmp < 0)
	{
		std::cerr << "Error: the amount of money cannot be negative!\n";
		exit(2);
	}
	else
		return tmp;
}

std::string bMoney::ldtoms(double ldin)
{
	/*if (ldin > LDBL_MAX)
	{
		cerr << "Ошибка: переполнение ldbl!";
		exit(1);
	}
	else if (ldin < 0)
	{
		cerr << "Ошибка: сумма не может быть отрицательной!";
		exit(1);
	}*/
	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << ldin;
	std::string strout;
	ss >> strout;
	strout.insert(0, "$");
	return strout;
}

bMoney bMoney::operator+(bMoney m2) const
{
	bool c = m2.money > MAX_LDBL_USR - money; // Переполнение в положительную сторону
	if (money != 0 && c)
	{
		std::cerr << "Error: overflow!\n";
		exit(1);
	}
	else
	{
		long double result = money + m2.money;
		return bMoney(result);
	}
}

bMoney bMoney::operator-(bMoney m2) const
{
	long double result = money - m2.money; 
	if (result < 0)
	{
		std::cerr << "Error: the amount of money cannot be negative!\n";
		exit(2);
	}
	else
		return bMoney(result);
}

bMoney bMoney::operator*(long double k) const
{
	if (money != 0 && abs(k) > MAX_LDBL_USR / money) // Переполнение в положительную сторону
	{
		std::cerr << "Error: overflow!\n";
		exit(1);
	}
	else if (k < 0)
	{
		std::cerr << "Eroor: the second multiplier cannot be negative!\n";
		exit(3);
	}
	else
	{
		long double result = money * k;
		return bMoney(result);
	}
}

long double bMoney::operator/(bMoney m2) const
{
	if (m2.money < 1 && m2.money != 0 && money > m2.money * MAX_LDBL_USR)
	{
		std::cerr << "Error: overflow!\n";
		exit(1);
	}
	else if (m2.money == 0)
	{
		std::cerr << "Error: division by zero!\n";
		exit(4);
	}
	else
		return money / m2.money;
}

bMoney bMoney::operator/(long double k) const
{

	if (k < 1 && k != 0 && money > k * MAX_LDBL_USR)
	{
		std::cerr << "Error: overflow!\n";
		exit(1);
	}
	else if(k==0)
	{
		std::cerr << "Error: division by zero!\n";
		exit(4);
	}
	else
	{
		long double tmp = money / k;
		return bMoney(tmp);
	}
}

bMoney::operator long double() const
{
	return money;
}