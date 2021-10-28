#pragma once
#include <iostream> 

class sterling;

class bMoney
{
private:
	long double money;
	static const long double MAX_LDBL_USR;
	static const double sterling_exRate; // Цена в фунтах стерлингах (в старом формате) одного доллара
public:
	bMoney();
	bMoney(std::string);
	bMoney(sterling); // Конструктор преобразования
	explicit bMoney(long double);
	void getMoney();
	void putMoney();
	long double mstold(std::string);
	std::string ldtoms(double);
	bMoney operator+(bMoney) const;
	bMoney operator-(bMoney) const;
	bMoney operator*(long double) const;
	long double operator/(bMoney) const;
	bMoney operator/(long double) const;
	operator long double() const;
};