#include <iostream>
using namespace std;

double power(double num, int exp = 2);

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите число: ";
	double num;
	cin >> num;
	cout << "Будете ли вводить степень? (y/n): ";
	char ch;
	cin >> ch;
	if (ch == 'y')
	{
		cout << "Введите степень: ";
		int exp;
		cin >> exp;
		num = power(num, exp);
	}
	else
		num = power(num);
	cout << num;
	return 0;
}


double power(double num, int exp)
{
	double powered_num = 1;
	for (int i = 0; i < exp; i++)
		powered_num *= num;
	return powered_num;
}
	