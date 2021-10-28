#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << setiosflags(ios::left) << setw(14) << "Фамилия" << setw(16) << "Имя" << setw(20) << "Адрес" << setw(17) << "Город" << endl
		<< setfill('-') << setw(66) << ' ' << setfill(' ') << endl
		<< setw(14) << "Петров" << setw(16) << "Василий" << setw(20) << "Кленовая 16" << setw(17) << "Санкт-Петербург" << endl
		<< setw(14) << "Иванов" << setw(16) << "Сергей" << setw(20) << "Осиновая 3" << setw(17) << "Находка" << endl
		<< setw(14) << "Сидоров" << setw(16) << "Иван" << setw(20) << "Березовая 21" << setw(17) << "Калининград" << endl;
	return 0;
}
