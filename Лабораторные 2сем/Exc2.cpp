/*=======================================
Name: Exc2.cpp
Author: Yunin Artem (Artemiiik)
Date: 23.06.2021
Version:
Copiright: freeware
Description:
A simple password generator
=======================================*/


#include <iostream>
#include <ctime>
#include <Windows.h>

// Рандом по мультипликативному конгруэнтному методу
unsigned int seed{ 1 };

unsigned int random()
{
	const int A{ 16807 };
	const int M{ 0x7FFFFFFF };
	return seed = seed * A % M;
}

unsigned int random(unsigned int min, unsigned int max)
{
	return min + random() % (max - min + 1);
}

void srandom(unsigned int _seed)
{
	seed = _seed;
}

////////////////////////////////////////////////////

char* generatePass(unsigned int len)
{
	srandom((unsigned int)time(nullptr));
	char* password{ new char[len + 1] };
	for (unsigned int i = 0; i < len; i++)
	{
		unsigned int charType{ random(0, 3) };
		switch (charType)
		{
		case 0:
			password[i] = random(33, 47);
			break;
		case 1:
			password[i] = random(48, 57);
			break;
		case 2:
			password[i] = random(65, 90);
			break;
		case 3:
			password[i] = random(97, 122);
			break;
		default:
			throw 1;
			break;
		}
	}
	password[len] = '\0';
	return password;
}

////////////////////////////////////////////////////

int main()
{
	SetConsoleOutputCP(1251);

	std::cout << "~Введите количество символов пароля: ";
	unsigned int count{ 16 };
	std::cin >> count;
	char* password{ generatePass(count) };
	std::cout << "~Сгенерированный пароль: " << password << std::endl;
	delete[] password;
	system("pause");
	return 0;
}
