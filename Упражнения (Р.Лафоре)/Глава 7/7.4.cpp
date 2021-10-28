#include <iostream>
#include <windows.h>
using namespace std;

unsigned int maxint(int[], const int);

int main()
{
	SetConsoleOutputCP(1251);

	const int MAX = 100;
	int a[MAX];
	int n = 0;

	cout << "Вводите числа (для остановки введите не число): ";
	while (cin >> a[n] && n < MAX)
		n++;

	int index_of_max = maxint(a, n);
	cout << "Индекс максимального элемента: " << index_of_max << " (число " << a[index_of_max] << ")\n";
	return 0;
}

unsigned int maxint(int arr[], const int SIZE)
{
	int index = 0, maximum = arr[0];
	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] > maximum)
		{
			maximum = arr[i];
			index = i;
		}
	}
	return index;
}

