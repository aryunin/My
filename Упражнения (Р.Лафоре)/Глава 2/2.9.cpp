#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int a, b, c, d;
	char dummychar;
	cout << "Введите первую дробь: ";
	cin >> a >> dummychar >> b;
	cout << "Введите вторую дробь: ";
	cin >> c >> dummychar >> d;
	a = a * d + b * c;
	b = b * d;
	cout << "Сумма равна: " << a << dummychar << b;
	return 0;
}