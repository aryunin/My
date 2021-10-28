#pragma once
#include <iostream>
#include <string.h> // для функций strcpy, strcat
#include <stdlib.h> // для функции exit
class String // наш класс для строк
{
private:
	enum { SZ = 80 }; // максимальный размер строки
	char str[SZ]; // массив для строки
public:
	// конструктор без параметров
	String()
	{
		strcpy_s(str, "");
	}
	// конструктор с одним параметром
	String(const char s[])
	{
		strcpy_s(str, s);
	}
	// конструктор с одним параметром
	void display() const
	{
		std::cout << str;
	}
	// оператор сложения
	String operator+(String) const;
	String operator+=(String);
};