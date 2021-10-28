#include "pch.h"
#include <iostream>
using namespace std;

int main() 
{
	setlocale(LC_ALL, "Rus");
    cout << "Введите температуру в градусах Цельсия: ";
    float cel;
    cin >> cel;
    float fahr = cel * (9/5.0) + 32;
    cout << cel << "(C) = " << fahr << "(F)\n";
	return 0;
}