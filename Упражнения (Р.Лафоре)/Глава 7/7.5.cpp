#include <iostream>
#include <windows.h>
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
	
	const int MAX = 100;
	fraction frac[MAX];
	int n = 0;

	char response;
	do
	{
		frac[n].getFract();
		n++;
		cout << "Желаете продолжить?(y/n): ";
		cin >> response; 
	} while (response != 'n' && n < MAX);

	fraction total = frac[0];
	for (int i = 1; i < n; i++)
		total = total.add(frac[i]);

	fraction divider(n, 1);
	fraction average = total.div(divider);

	cout << "Среднее значение: "; average.showFract();
	return 0;
}
