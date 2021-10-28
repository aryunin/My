#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Нажмите 1 для перевода шкалы Цельсия в шкалу Фаренгейта\n2 для перевода шкалы Фаренгейта в шкалу Цельсия: ";
	char mode;
	cin >> mode;
	float cel, fahr;
	switch (mode)
	{
	case '1':
		cout << "Введите температуру по Цельсию: ";
		cin >> cel;
		fahr = (9 / 5.0)*cel + 32;
		cout << fahr;
		cout << "Значение по Фаренгейту: " << fahr << endl;
		break;
	case '2':
		cout << "Введите температуру по Фаренгейту: ";
		cin >> fahr;
		cel = (fahr - 32) / (9 / 5.0);
		cout << "Значение по Цельсию:" << cel << endl;
		break;
	default: cerr << "Режим работы выбран неверно" << endl;
	}
	return 0;
} 