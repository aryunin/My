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
	char dummychar, operation;
	char response;
	do {
		cout << "Введите обыкновенную дробь, знак операции и ещё одну обыкновенную дробь (5/4 * 4/5): ";
		cin >> value1.numerator >> dummychar >> value1.denominator >> operation >> value2.numerator >> dummychar >> value2.denominator;
		switch (operation)
		{
		case '+': result.numerator = value1.numerator * value2.denominator + value1.denominator * value2.numerator; result.denominator = value1.denominator * value2.denominator; break;
		case '-': result.numerator = value1.numerator * value2.denominator - value1.denominator * value2.numerator; result.denominator = value1.denominator * value2.denominator; break;
		case '*': result.numerator = value1.numerator * value2.numerator; result.denominator = value1.denominator * value2.denominator; break;
		case '/': result.numerator = value1.numerator * value2.denominator; result.denominator = value1.denominator * value2.numerator; break;
		default: cerr << "Неверная операция"; exit(1);
		}
		cout << "Результат: " << result.numerator << '/' << result.denominator
			<< "\nЖелаете ввести ещё одну операцию? (y/n): ";
		cin >> response;
	} while (response == 'y');
	return 0;
}