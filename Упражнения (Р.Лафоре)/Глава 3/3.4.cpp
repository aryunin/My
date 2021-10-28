#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	double firstval, secondval, result;
	char operation, response;
	do
	{
		cout << "Введите первый операнд, операцию и второй операнд: ";
		cin >> firstval >> operation >> secondval;
		switch (operation)
		{
		case '*': result = firstval * secondval; break;
		case '/': result = firstval / secondval; break;
		case '+': result = firstval + secondval; break;
		case '-': result = firstval - secondval; break;
		default: cout << "Неверная операция" << endl; exit(1);
		}
		cout << "Результат равен " << result
			<< "\nВыполнить ещё одну операцию (y/n)? ";
		cin >> response;
	} while (response == 'y');
	return 0;
} 