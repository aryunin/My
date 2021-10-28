#include <iostream>
using namespace std;

struct fraction
{
	int numerator;
	int denominator;
};

int main()
{
	setlocale(LC_ALL, "Rus");
	fraction value1;
	fraction value2;
	fraction result;
	char dummychar;
	cout << "Введите первую дробь: ";
	cin >> value1.numerator >> dummychar >> value1.denominator;
	cout << "Введите вторую дробь: ";
	cin >> value2.numerator >> dummychar >> value2.denominator;
	result.numerator = value1.numerator * value2.denominator + value1.denominator * value2.numerator;
	result.denominator = value1.denominator * value2.denominator;
	cout << "Сумма равна: " << result.numerator << dummychar << result.denominator;
}