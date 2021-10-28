#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	char response;
	do {
		cout << "Введите обыкновенную дробь, знак операции и ещё одну обыкновенную дробь (5/4 * 4/5): ";
		int a, b, c, d, reduction = 1;
		char dummychar, operation;
		cin >> a >> dummychar >> b >> operation >> c >> dummychar >> d;
		if (b == 0 || d == 0)
		{
			cerr << "Деление на 0 не возможно";
			exit(1);
		}
		switch (operation)
		{
		case '+': a = a * d + b * c; b *= d; break;
		case '-': a = a * d - b * c; b *= d; break;
		case '*': a *= c; b *= d; break;
		case '/': a *= d; b *= c; break;
		default: cerr << "Неверная операция"; exit(1);
		}
		cout << "Результат: " << a << '/' << b
			<< "\nЖелаете ввести ещё одну операцию? (y/n): ";
		cin >> response;
	} while (response == 'y');
	return 0;
}