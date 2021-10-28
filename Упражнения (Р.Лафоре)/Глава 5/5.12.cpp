#include <iostream>
using namespace std;

struct fraction
{
	int numerator;
	int denominator;
};

fraction fadd(fraction f1, fraction f2);
fraction fsub(fraction f1, fraction f2);
fraction fmul(fraction f1, fraction f2);
fraction fdiv(fraction f1, fraction f2);
fraction reduction(fraction ff);

int main()
{
	setlocale(LC_ALL, "Rus");
	fraction f1;
	fraction f2;
	fraction result;
	char dummychar, operation;
	char response;
	do {
		cout << "Введите обыкновенную дробь, знак операции и ещё одну обыкновенную дробь (5/4 * 4/5): ";
		cin >> f1.numerator >> dummychar >> f1.denominator >> operation >> f2.numerator >> dummychar >> f2.denominator;
		switch (operation)
		{
		case '+': result = fadd(f1, f2); break;
		case '-': result = fsub(f1, f2); break;
		case '*': result = fmul(f1, f2); break;
		case '/': result = fdiv(f1, f2); break;
		default: cerr << "Неверная операция"; exit(1);
		}
		if (result.numerator % result.denominator == 0)
		{
			cout << "Результат: " << result.numerator / result.denominator << endl;
		}
		else
		{
			result = reduction(result);
			cout << "Результат: " << result.numerator << '/' << result.denominator << endl;
		}
		cout << "Желаете ввести ещё одну операцию? (y/n): ";
		cin >> response;
	} while (response == 'y');
	return 0;
}

fraction fadd(fraction f1, fraction f2)
{
	fraction f_sum;
	f_sum.numerator = f1.numerator * f2.denominator + f1.denominator * f2.numerator;
	f_sum.denominator = f1.denominator * f2.denominator;
	return f_sum;
}

fraction fsub(fraction f1, fraction f2)
{
	fraction f_diff;
	f_diff.numerator = f1.numerator * f2.denominator - f1.denominator * f2.numerator;
	f_diff.denominator = f1.denominator * f2.denominator;
	return f_diff;
}

fraction fmul(fraction f1, fraction f2)
{
	fraction f_prod;
	f_prod.numerator = f1.numerator * f2.numerator;
	f_prod.denominator = f1.denominator * f2.denominator;
	return f_prod;
}

fraction fdiv(fraction f1, fraction f2)
{
	fraction f_quot;
	f_quot.numerator = f1.numerator * f2.denominator;
	f_quot.denominator = f1.denominator * f2.numerator;
	return f_quot;
}

fraction reduction(fraction ff)
{
	if (abs(ff.numerator) > abs(ff.denominator))
	{
		for (int i = abs(ff.denominator) / 2; i > 0; i--)
		{
			if (ff.denominator % i == 0 && ff.numerator % i == 0)
			{
				ff.denominator /= i;
				ff.numerator /= i;
				break;
			}
		}
	}	
	else if (abs(ff.numerator) < abs(ff.denominator))
	{
		if (ff.denominator % ff.numerator == 0)
		{
			ff.denominator /= ff.numerator;
			ff.numerator = 1;
		}
		for (int i = abs(ff.numerator) / 2; i > 0; i--)
		{
			if (ff.denominator % i == 0 && ff.numerator % i == 0)
			{
				ff.denominator /= i;
				ff.numerator /= i;
				break;
			}
		}

	}
	return ff;
}