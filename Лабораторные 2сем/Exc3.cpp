/*=======================================
Name: Exc3.cpp
Author: Yunin Artem (Artemiiik)
Date: 23.06.2021
Version: 
Copiright: freeware
Description:
A simple letter counter
=======================================*/

#include <iostream>
#include <Windows.h>
#include <string>
#include <map>

int toLower(unsigned char ch) // tolower() для СP-1251 с поддержкой русского языка
{
	if (ch >= 65 && ch <= 90 || ch >= 192 && ch <= 223)
		ch += 32;
	else if (ch == 168) 
		ch = 184;
	return ch;
}

using charUIntMap = std::map<unsigned char, unsigned int>;

charUIntMap* func(const std::string& str)
{
	charUIntMap* mp{ new charUIntMap };
	std::string::const_iterator sIt;
	for (sIt = str.cbegin(); sIt != str.cend(); sIt++)
	{
		unsigned char ch{ (unsigned char)toLower(*sIt) };
		if (ch >= 97 && ch <= 122 || 
			ch >= 224 && ch <= 255 || ch == 184)
			((*mp)[ch])++; // начальные значения unsigned int-элементов map по умолчанию нули
	}
	return mp;
}

int main()
{
	// Кодировка консоли
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Ввод
	std::cout << "~Введите текст: ";
	std::string str;
	std::getline(std::cin, str);

	// Решение 
	charUIntMap* mp{ func(str) }; 

	// Вывод
	charUIntMap::const_iterator mIt;
	for (mIt = mp->cbegin(); mIt != mp->cend(); mIt++)
		std::cout << '\'' << mIt->first << "\' - " << mIt->second << "ps\n";
}