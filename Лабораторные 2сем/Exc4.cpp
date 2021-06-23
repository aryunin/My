/*=======================================
Name: Exc4.cpp
Author: Yunin Artem (Artemiiik)
Date: 23.06.2021
Version:
Copiright: freeware
Description:
A simple sort programm
=======================================*/


#include <iostream>
#include <Windows.h>
using namespace std;

// Сортировка вставками
void insertSort(double* arr, const int N, const bool direct)
{
	for (int i{ 1 }; i  < N; i++)
	{
		double tmp{ arr[i] };
		int k{ i - 1 };
		while (k >= 0 && (tmp < arr[k] == direct))
		{
			arr[k + 1] = arr[k];
			k--;
		}
		arr[k + 1] = tmp;
	}
}

///////////////////////////////////////////////////////////////////////

int main()
{
	SetConsoleOutputCP(1251);
	
	cout << "~Введите количесвто чисел: ";
	int count{};
	cin >> count;
	double* arr{ new double[count] };

	cout << "~Вводите числа: ";
	for (int i{ 0 }; i < count; i++)
		cin >> arr[i];

	cout << "\n~Введите направление сортировки\n(0 - по убыванию, др. значение - по возрастанию): ";
	bool direct{};
	cin >> direct;

	insertSort(arr, count, direct);

	cout << "\n~Отсортированная последовательность:\n";
	for (int i = 0; i < count; i++)
		cout << arr[i] << ' ';

	cout << endl;
}
