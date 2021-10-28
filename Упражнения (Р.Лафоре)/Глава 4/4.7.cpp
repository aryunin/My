#include <iostream>
#include <iomanip>
using namespace std;  

enum etype { laborer, secretary, manager, accountant, executive, researcher };

struct Date { int day, mounth, year; };

struct employee
{
	int id;
	float benefit;
	etype position;
	Date appointment_date;
};

int main()
{
	setlocale(LC_ALL, "Rus");
	employee worker1, worker2, worker3;
	char separator, letter;
	cout << "Введите номер, пособие, первую букву должности и дату назначения (dd/mm/yyyy) первого сотрудника: ";
	cin >> worker1.id >> worker1.benefit >> letter >> worker1.appointment_date.day >> separator >> worker1.appointment_date.mounth >> separator >> worker1.appointment_date.year;
	switch (letter)
	{
	case 'l': worker1.position = laborer; break;
	case 's': worker1.position = secretary; break;
	case 'm': worker1.position = manager; break;
	case 'a': worker1.position = accountant; break;
	case 'e': worker1.position = executive; break;
	case 'r': worker1.position = researcher; break;
	}
	cout << "Введите номер, пособие, первую букву должности и дату назначения (dd/mm/yyyy) второго сотрудника: ";
	cin >> worker2.id >> worker2.benefit >> letter >> worker2.appointment_date.day >> separator >> worker2.appointment_date.mounth >> separator >> worker2.appointment_date.year;
	switch (letter)
	{
	case 'l': worker2.position = laborer; break;
	case 's': worker2.position = secretary; break;
	case 'm': worker2.position = manager; break;
	case 'a': worker2.position = accountant; break;
	case 'e': worker2.position = executive; break;
	case 'r': worker2.position = researcher; break;
	}
	cout << "Введите номер, пособие, первую букву должности и дату назначения (dd/mm/yyyy) третьего сотрудника: ";
	cin >> worker3.id >> worker3.benefit >> letter >> worker3.appointment_date.day >> separator >> worker3.appointment_date.mounth >> separator >> worker3.appointment_date.year;
	switch (letter)
	{
	case 'l': worker3.position = laborer; break;
	case 's': worker3.position = secretary; break;
	case 'm': worker3.position = manager; break;
	case 'a': worker3.position = accountant; break;
	case 'e': worker3.position = executive; break;
	case 'r': worker3.position = researcher; break;
	}
	cout << endl << setw(7) << "Номер:" << setw(10) << "Пособие:" << setw(18) << "Дата назначения:" << setw(12) << "Должность:" << endl
		<< setw(7) << worker1.id << setw(10) << worker1.benefit << setw(8) << ' ' << setw(2) << setfill('0') 
		<< worker1.appointment_date.day << '/' << setw(2) << worker1.appointment_date.mounth << '/' << worker1.appointment_date.year << setfill(' ') << setw(12);
	switch (worker1.position)
	{
	case 1: cout << "laborer" << endl; break;
	case 2: cout << "secretary" << endl; break;
	case 3: cout << "manager" << endl; break;
	case 4: cout << "accountant" << endl; break;
	case 5: cout << "executive" << endl; break;
	case 6: cout << "researcher" << endl; break;
	}
	cout << setw(7) << worker2.id << setw(10) << worker2.benefit << setw(8) << ' ' << setw(2) << setfill('0')
		<< worker2.appointment_date.day << '/' << setw(2) << worker2.appointment_date.mounth << '/' << worker2.appointment_date.year << setfill(' ') << setw(12);
	switch (worker2.position)
	{
	case 1: cout << "laborer" << endl; break;
	case 2: cout << "secretary" << endl; break;
	case 3: cout << "manager" << endl; break;
	case 4: cout << "accountant" << endl; break;
	case 5: cout << "executive" << endl; break;
	case 6: cout << "researcher" << endl; break;
	}
	cout << setw(7) << worker3.id << setw(10) << worker3.benefit << setw(8) << ' ' << setw(2) << setfill('0')
		<< worker3.appointment_date.day << '/' << setw(2) << worker3.appointment_date.mounth << '/' << worker3.appointment_date.year << setfill(' ') << setw(12);
	switch (worker3.position)
	{
	case 1: cout << "laborer" << endl; break;
	case 2: cout << "secretary" << endl; break;
	case 3: cout << "manager" << endl; break;
	case 4: cout << "accountant" << endl; break;
	case 5: cout << "executive" << endl; break;
	case 6: cout << "researcher" << endl; break;
	}
}
