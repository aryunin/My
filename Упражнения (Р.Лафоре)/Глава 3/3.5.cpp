#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	for (int i = 0, j = 1; i < 20; i++, j += 2)
	{
		for (int k = 0; k < 39; k++)
		{
			if (39 - k <= j) cout << 'X';
			else cout << ' ';
		}
		cout << '\n';
	}
	return 0;
} 