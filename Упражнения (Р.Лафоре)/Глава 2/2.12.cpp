#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	float modern_pounds; 
	cout << "Введите число десятичных фунтов: ";
	cin >> modern_pounds;
	int pounds = static_cast<int>(modern_pounds);
	int frac = (modern_pounds - pounds)*100;
	int shillings = frac * 2.4 / 12;
	int pence = static_cast<int>(frac * 2.4 + 0.5) % 12;
	cout << "Эквивалентная сумма в старой форме записи: " << pounds << '.' << shillings << '.' << pence << endl;
	return 0;
}
