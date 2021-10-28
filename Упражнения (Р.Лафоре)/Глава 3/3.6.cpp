#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	unsigned int numb;
	unsigned long fact = 1;
	cout << "Введите натуральное число: ";
	cin >> numb;
	do {
		for (int i = numb; i > 0; i--)
			fact *= i;
		cout << "Факториал числа равен " << fact << endl;
		fact = 1;
		cout << "Введите натуральное число (0 - завершить выполнение программы): ";
		cin >> numb;
	} while (numb != 0);
	return 0;
} 