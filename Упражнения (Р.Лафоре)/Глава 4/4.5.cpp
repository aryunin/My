#include <iostream>
#include <iomanip>
using namespace std; 

struct Date { int day, mounth, year; };

int main()
{
	setlocale(LC_ALL, "Rus");
	Date date;
	cout << "Введите день, месяц и год в формате (dd/mm/yyyy): ";
	char delimiter;
	cin >> date.day >> delimiter >> date.mounth >> delimiter >> date.year;
	cout << "Вы ввели: " << setfill('0') << setw(2) << date.day << delimiter << setw(2) << date.mounth << delimiter << setw(4) << date.year;
}
