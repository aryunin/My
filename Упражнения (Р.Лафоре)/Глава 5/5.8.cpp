#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите пару числовых значений, разделяя их пробелом: ";
	int first, second;
	cin >> first >> second;
	swap(first, second);
	cout << first << ' ' << second << endl;
	return 0;
}


void swap(int& first, int& second)
{
	int tmp = first;
	first = second;
	second = tmp;
}
