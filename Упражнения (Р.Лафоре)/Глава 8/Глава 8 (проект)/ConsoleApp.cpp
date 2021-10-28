#include <iostream>
#include <Windows.h>
#include "sterling.h"
#include "bMoney.h"
using namespace std;

int main()
{
	SetConsoleOutputCP(1252);
	sterling s = { 1, 10, 0 };
	bMoney d = s;
	d.getMoney(); cout << " = "; s.getSterling(); //TODO: тесты и преобразование sterling в bMoney
	return 0;
}
