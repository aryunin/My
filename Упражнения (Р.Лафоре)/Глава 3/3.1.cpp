#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите число: ";
	int val;
	cin >> val;
	for (int i = 1; i <= 200; i++) 
	{
		cout << setw(5) << val * i;
		if (val*i % 10 == 0) cout << endl;
	}
	return 0;
}