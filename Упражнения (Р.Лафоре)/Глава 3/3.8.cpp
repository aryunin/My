#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	char response;
	do {
		cout << "Введите первую сумму: ";
		int pounds_first, shillings_first, pence_first;	// Первая сумма
		cin >> pounds_first >> shillings_first >> pence_first;
		cout << "Введите вторую сумму: ";
		int pounds_second, shillings_second, pence_second; // Вторая сумма
		cin >> pounds_second >> shillings_second >> pence_second;
		if (pounds_first < 0 || shillings_first < 0 || pence_first < 0 || pence_second < 0 || shillings_second < 0 || pounds_second < 0)
		{
			cerr << "Ошибка, все значения должны быть неотрицательными\n";
			exit(1);
		}
		int pounds_result, shillings_result, pence_result;
		pounds_result = pounds_first + pounds_second;
		shillings_result = shillings_first + shillings_second;
		pence_result = pence_first + pence_second;
		if (pence_result >= 12)
		{
			pence_result -= 12;
			shillings_result++;
		}
		if (shillings_result >= 20)
		{
			shillings_result -= 20;
			pounds_result++;
		}
		cout << "Всего " << pounds_result << ' ' << shillings_result << ' ' << pence_result
			<< "\nЖелаете ввести ещё одну операцию? (y/n): ";
		cin >> response;
	} while (response == 'y');
	return 0;
}