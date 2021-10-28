#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите количество долларов: ";
	float dollars;
	cin >> dollars;
	float pounds = dollars / 1.487;
	float francs = dollars / 0.172;
	float marks = dollars / 0.584;
	float yens = dollars / 0.00955;
	cout << dollars << " долларов - это:\n"
		<< pounds << " фунтов стерлингов\n"
		<< francs << " франков\n"
		<< marks << " немецких марк\n" << yens << " японских йен\n";
	return 0;
}