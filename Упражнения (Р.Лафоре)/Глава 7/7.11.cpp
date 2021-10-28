#include <iostream>
#include <sstream>
#include <iomanip>
#include <Windows.h>
using namespace std;

class money
{
public:
	string ldtoms(long double); // преобразование long double в строку
};

string money::ldtoms(long double ldin)
{
	if (ldin > LDBL_MAX)
	{
		cerr << "Ошибка: лишком большое число!";
		exit;
	}
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
	money cash;
	long double ldcash;
	cout << "Введите сумму: ";
	cin >> ldcash;
	string scash = cash.ldtoms(ldcash);
	cout << scash;
	return 0;
}
