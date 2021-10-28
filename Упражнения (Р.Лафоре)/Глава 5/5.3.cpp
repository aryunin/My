#include <iostream>
using namespace std;

void zeroSmaller(int& first_val, int& second_val);

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите через пробел два числа: ";
	int first, second;
	cin >> first >> second;
	zeroSmaller(first, second);
	cout << "Меньшее из двух чисел изменено на 0: " << first << ' ' << second << endl;
	return 0;
}

void zeroSmaller(int& first_val, int& second_val)
{
	if (first_val > second_val)
		second_val = 0;
	else if (first_val < second_val)
		first_val = 0;
	else
	{
		first_val = 0;
		second_val = 0;
	}
}

	