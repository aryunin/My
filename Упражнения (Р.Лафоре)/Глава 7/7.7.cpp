#include <iostream>
#include <sstream>
#include <iomanip>
#include <Windows.h>
using namespace std;

class money
{
public:
	long double mstold(string); // преобразование строки в long double
};

long double money::mstold(string sin)
{
	string available = "0123456789."; // символы, которые не будут игнорироваться при преобразовании
	stringstream ss;
	// исключение лишних символов
	for (int i = 0; i < sin.size(); i++)
		if (available.find(sin.at(i)) != -1)
			ss << sin.at(i);
	// преобразование в long double
	long double tmp;
	ss >> tmp; 
	return tmp;
}

int main()
{
	SetConsoleOutputCP(1251);
	money cash;
	string scash;
	cout << "Введите сумму: ";
	getline(cin, scash);
	long double dcash = cash.mstold(scash);
	cout << fixed << setprecision(2) << dcash << endl;
	return 0;
}
