#include <iostream>
#include <Windows.h>
using namespace std;

class fraction
{
private:
	int numerator;
	int denominator;
public:
	fraction() : numerator(1), denominator(1)
	{ }
	fraction(int num, int den) : numerator(num), denominator(den)
	{ }
	void getfraction()
	{
		char dummychar;
		cin >> numerator >> dummychar >> denominator;
	}
	void display() const
	{
		cout << numerator << '/' << denominator;
	}
	fraction add(fraction frac) const;
};

fraction fraction::add(fraction frac) const
{
	int num = numerator * frac.denominator + frac.numerator * denominator;
	int den = denominator * frac.denominator;
	fraction tmp(num, den);
	return tmp;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	char response;
	do
	{
		fraction frac1, frac2, frac3;
		cout << "Введите первую дробь (x/x): ";
		frac1.getfraction();
		cout << "Введите вторую дробь (x/x): ";
		frac2.getfraction();
		cout << "Сумма: ";
		frac3 = frac1.add(frac2);
		frac3.display();
		cout << "\nЖелаете продолжить?(Д/Н): ";
		cin >> response;
	} while (response == 'Д');
	return 0;
}
