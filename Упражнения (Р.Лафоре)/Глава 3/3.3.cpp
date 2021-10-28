#include "pch.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите число: ";
	long value = 0;
	int num;
	num = _getche();
	while (num != '\r')
	{
		value = value * 10 + num - 48;
		num = _getche();
	}
	cout << endl << "Вы ввели число " << value << endl;
	return 0;
} 