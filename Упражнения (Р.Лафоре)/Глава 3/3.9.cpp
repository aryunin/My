#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите количество гостей: "; 
	int guests; 
	cin >> guests;
	if (guests < 0)
	{
		cerr << "Количество гостей не может быть меньше 0";
		exit(1);
	}
	cout << "Введите количество стульев: ";
	int chairs;
	cin >> chairs;
	if (chairs < 0)
	{
		cerr << "Количество стульев не может быть меньше 0";
		exit(1);
	}
	unsigned long seat_variants = 1;
	if (chairs == 0 || guests == 0)
		seat_variants = 0;
	else
		for (int i = 0; i < chairs; i++, guests--)
			seat_variants *= guests;
	cout << "Возможных вариантов посадки: " << seat_variants << endl;
	return 0;
}