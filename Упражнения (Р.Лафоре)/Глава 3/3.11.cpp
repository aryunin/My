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
		if (pounds_first < 0 || shillings_first < 0 || pence_first < 0) 
		{
			cerr << "Ошибка, все значения должны быть неотрицательными\n";
			exit(1);
		}
		cout << "Введите опперацию: ";
		char operation;
		cin >> operation;
		int pounds_result, shillings_result, pence_result;	// Результирующая сумма

		switch (operation)	// Переводим все в пенсы и выполняем над ними действия
		{
		case '*':
			cout << "Введите число, на которое вы хотите умножить вашу сумму: ";
			float multiplier;
			cin >> multiplier;
			if (multiplier < 0) 
			{
				cerr << "Умножение на отрицательное число не имеет смысла\n";
				exit(1);
			}
			pence_result = static_cast<int>((20 * 12 * pounds_first + 12 * shillings_first + pence_first) * multiplier);	
			break;
		case '/':
			cout << "Введите число, на которое вы хотите разделить вашу сумму: ";
			float divider;
			cin >> divider;
			if (divider <= 0)
			{
				cerr << "Деление на неположительное число не имеет смысла\n";
				exit(1);
			}
			pence_result = static_cast<int>((20 * 12 * pounds_first + 12 * shillings_first + pence_first) / divider);
			break;
		case '+':
			cout << "Введите вторую сумму: ";
			int pounds_second, shillings_second, pence_second;
			cin >> pounds_second >> shillings_second >> pence_second;
			if (pounds_second < 0 || shillings_second < 0 || pence_second < 0)
			{
				cerr << "Ошибка, все значения должны быть неотрицательными\n";
				exit(1);
			}
			pence_result = 20 * 12 * (pounds_first + pounds_second) + 12 * (shillings_first + shillings_second) + pence_first + pence_second;
			break;
		case '-':
			cout << "Введите вторую сумму: ";
			cin >> pounds_second >> shillings_second >> pence_second;
			if (pounds_second < 0 || shillings_second < 0 || pence_second < 0)
			{
				cerr << "Ошибка, все значения должны быть неотрицательными\n";
				exit(1);
			}
			pence_result = 20 * 12 * (pounds_first - pounds_second) + 12 * (shillings_first - shillings_second) + pence_first - pence_second;
			if (pence_result < 0)
			{
				cerr << "Вычитание не имеет смысла, так как вторая сумма больше первой, результат отрицательный\n";
				exit(1);
			}
			break;
		default: 
			cerr << "Неверная операция\n";
			exit(1);
		}

		// Перевод результата из пенсов в нормальный вид (фунты, шилинги, пенсы)
		shillings_result = pence_result / 12;
		pounds_result = shillings_result / 20;
		shillings_result %= 20;
		pence_result %= 12;

		cout << "Всего " << pounds_result << ' ' << shillings_result << ' ' << pence_result 
			<< "\nЖелаете ввести ещё одну операцию? (y/n): ";
		cin >> response;
	} while (response == 'y');
	return 0;
} 