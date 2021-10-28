#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int pounds, shillings, pence;
	cout << "Введите количество фунтов: ";
	cin >> pounds;
	cout << "Введите количество шиллингов: ";
	cin >> shillings;
	cout << "Введите количество пенсов: ";
	cin >> pence;
	float modern_pounds = pounds + static_cast<short int>((shillings*12 + pence)/2.4 + 0.5)/100.0;
	cout << "Десятичных фунтов: " << modern_pounds << endl;
	return 0;
}
