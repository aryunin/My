#include "pch.h"
#include <iostream>
using namespace std;

struct phone
{
	int city_code;
	int station_number;
	int abonent_number;
};

int main()
{
	setlocale(LC_ALL, "Rus");
	phone mine_number{ 212, 767, 8900 },
		custom_number;
	cout << "Введите код города, номер станции и номер абонента, разделяя пробелом: ";
	cin >> custom_number.city_code >> custom_number.station_number >> custom_number.abonent_number;
	cout << "Мой номер: (" << mine_number.city_code << ") " << mine_number.station_number << "-" << mine_number.abonent_number << endl
		<< "Ваш номер: (" << custom_number.city_code << ") " << custom_number.station_number << "-" << custom_number.abonent_number << endl;
	return 0;
}