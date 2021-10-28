#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	float deposit, rate, result;
	int years;
	cout << "Введите начальный вклад: ";
	cin >> deposit;
	cout << "Введите число лет: ";
	cin >> years;
	cout << "Введите процентную ставку: ";
	cin >> rate;
	result = deposit;
	for (int i = 0; i < years; i++)
	{
		result += result * rate / 100;
	}
	cout << "Через " << years << " вы получите " << result << " доллара" << endl;
	return 0;
} 