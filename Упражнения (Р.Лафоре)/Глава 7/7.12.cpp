#include <iostream>
#include <sstream> 
#include <iomanip> 
#include <Windows.h>
using namespace std;

class bMoney
{
private:
	double money;
	static const double MAX_LDBL;
public:
	bMoney() : money(0)
	{ }
	bMoney(string s)
	{
		money = mstold(s);
	}
	void getmoney();
	void putmoney();
	long double mstold(string);
	string ldtoms(double);
	void madd(bMoney m1, bMoney m2);
};
const double bMoney::MAX_LDBL = 999999999999990.00;

void bMoney::getmoney()
{
	string strout = ldtoms(money);
	cout << strout;
}

void bMoney::putmoney()
{
	string strin;
	cin >> strin;
	money = mstold(strin);
}

void bMoney::madd(bMoney m1, bMoney m2) 
{
	/*bool overflow = false;
	if (m1.money + m2.money > LDBL_MAX)	
		overflow = true;
	if (overflow == true)
	{
		cerr << "Ошибка: переполнение ldbl";
		exit(1);
	}
	---------
		Число изначально не может быть больше MAX_LDBL -> сумма таких чисел не даст переполнения
	---------
	*/
	money = m1.money + m2.money;
}

long double bMoney::mstold(string sin)
{
	string available = "-0123456789."; // символы, которые не будут игнорироваться при преобразовании
	stringstream ss;
	// исключение лишних символов
	for (int i = 0; i < sin.size(); i++)
		if (available.find(sin.at(i)) != -1)
			ss << sin.at(i);
	// преобразование в long double
	double tmp;
	ss >> fixed >> setprecision(2) >> tmp;
	if (tmp > MAX_LDBL)
	{
		cerr << "Ошибка: переполнение ldbl!";
		exit(1);
	}
	else if (tmp < 0)
	{
		cerr << "Ошибка: сумма не может быть отрицательной!";
		exit(1);
	}
	else
		return tmp;
}

string bMoney::ldtoms(double ldin)
{
	/*if (ldin > LDBL_MAX)
	{
		cerr << "Ошибка: переполнение ldbl!";
		exit(1);
	}
	else if (ldin < 0)
	{
		cerr << "Ошибка: сумма не может быть отрицательной!";
		exit(1);
	}*/
	stringstream ss;
	ss << fixed << setprecision(2) << ldin;
	string strout;
	ss >> strout;
	strout.insert(0, "$");
	return strout;
}

int main()
{
	SetConsoleOutputCP(1251);

	string cash1;
	cout << "Введите первую сумму: ";
	cin >> cash1;
	bMoney money1(cash1);
	
	cout << "Введите вторую сумму: ";
	bMoney money2;
	money2.putmoney();

	bMoney money3;
	money3.madd(money1, money2);

	cout << "Сумма: ";
	money3.getmoney();
	return 0;
}
