#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	float deposit, rate, desired_amount; 
	int years = 0;
	cout << "Введите начальный вклад: ";
	cin >> deposit;
	cout << "Введите процентную ставку: ";
	cin >> rate;
	cout << "Введите желаемую сумму: ";
	cin >> desired_amount;
	for ( ; deposit < desired_amount; years++)
	{
		deposit = deposit + deposit * rate / 100;
	}
	cout << "Для получения " << desired_amount << " долларов с процентной ставкой " << rate << "%, вам понадобится " << years << " лет." << endl;
	return 0;
} 