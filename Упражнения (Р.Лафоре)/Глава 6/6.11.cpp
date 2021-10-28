#include <iostream>
#include <Windows.h>
#include <cmath>
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
	void getFract()
	{
		char dummychar;
		cin >> numerator >> dummychar >> denominator;
	}
	void lowterms();
	void showFract() const
	{
		cout << numerator << '/' << denominator;
	}
	fraction add(fraction ff) const;
	fraction dif(fraction ff) const;
	fraction mul(fraction ff) const;
	fraction div(fraction ff) const;

};

fraction fraction::add(fraction ff) const
{
	int num = numerator * ff.denominator + ff.numerator * denominator;
	int den = denominator * ff.denominator;
	fraction tmp(num, den);
	tmp.lowterms();
	return tmp;
}

fraction fraction::dif(fraction ff) const
{
	int num = numerator * ff.denominator - ff.numerator * denominator;
	int den = denominator * ff.denominator;
	fraction tmp(num, den);
	tmp.lowterms();
	return tmp;
}

fraction fraction::mul(fraction ff) const
{
	int num = numerator * ff.numerator;
	int den = denominator * ff.denominator;
	fraction tmp(num, den);
	tmp.lowterms();
	return tmp;
}

fraction fraction::div(fraction ff) const
{
	int num = numerator * ff.denominator;
	int den = denominator * ff.numerator;
	fraction tmp(num, den);
	tmp.lowterms();
	return tmp;
}

void fraction::lowterms() 
{
	long tnum, tden, temp, gcd;
	tnum = labs(numerator); 
	tden = labs(denominator);
	if (tden == 0) 
	{
		cout << "Недопустимый знаменатель!"; exit(1);
	}
	else if (tnum == 0) 
	{
		numerator = 0; denominator = 1; return;
	}
	while (tnum != 0)
	{
		if (tnum < tden)
		{
			temp = tnum; tnum = tden; tden = temp;
		} 
		tnum = tnum - tden; 
	}
	gcd = tden;
	numerator = numerator / gcd; 
	denominator = denominator / gcd;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	fraction f1, f2, f3;
	char operation;
	char response;
	do {
		cout << "Введите обыкновенную дробь, знак операции и ещё одну обыкновенную дробь (5/4 * 4/5): ";
		f1.getFract(); cin >> operation; f2.getFract();
		switch (operation)
		{
		case '+': f3 = f1.add(f2); break;
		case '-': f3 = f1.dif(f2); break;
		case '*': f3 = f1.mul(f2); break;
		case '/': f3 = f1.div(f2); break;
		default: cerr << "Неверная операция"; exit(1);
		}
		f3.showFract();
		cout << "\nЖелаете ввести ещё одну операцию? (Д/Н): ";
		cin >> response;
	} while (response == 'Д');
	return 0;
}
