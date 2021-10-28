#include "String.h"
#include <iostream>
#include <string.h> // для функций strcpy, strcat
#include <stdlib.h> // для функции exit

String String::operator+(String ss) const
{
	String temp; // временная переменная
	if (strlen(str) + strlen(ss.str) < SZ)
	{
		strcpy_s(temp.str, str); // копируем содержимое первой строки
		strcat_s(temp.str, ss.str); // добавляем содержимое второй строки
	}
	else
	{
		std::cout << "\nПереполнение!";
		exit(1);
	}
	return temp; // возвращаем результат
}

String String::operator+=(String ss)
{
	if (strlen(str) + strlen(ss.str) < SZ)
		strcat_s(str, ss.str); // добавляем содержимое второй строки
	else
	{
		std::cout << "\nПереполнение!";
		exit(1);
	}
	String temp;
	strcpy_s(temp.str, str);
	return temp; // возвращаем результат
}
