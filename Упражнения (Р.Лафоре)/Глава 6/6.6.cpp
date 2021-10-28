#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
using namespace std;

enum etype { laborer, secretary, manager, accountant, executive, researcher };

class Date
{
private:
	int day, mounth, year;
	char dummychar;
public:
	Date() : day(1), mounth(1), year(2000), dummychar('/')
	{ }
	void getdate()
	{
		cin >> day >> dummychar >> mounth >> dummychar >> year;
	}
	void display() const
	{
		cout << setfill('0') << setw(2) << day << dummychar << setw(2) << mounth << dummychar << setw(4) << year << setfill(' ');
	}
};

class employee
{
private:
	static int number;
	static bool istablecreated;
	int id;
	etype position_num;
	Date employment_date;
	float benefit;
public:
	employee() : id(0), position_num(laborer), benefit(0.0)
	{ getemployee(); }
	void getemployee();
	void create_table() const;
	void display() const;
};

int employee::number = 1;
bool employee::istablecreated = false;

void employee::create_table() const
{
	cout << setw(9) << "Сотрудник" << setw(6) << "ID" << setw(12) << "Должность" << setw(13) << "Дата приема" << setw(10) << "Оклад" << endl;
	istablecreated = true;
}

void employee::getemployee()
{
	cout << "Введите ID сотрудника: ";
	cin >> id;
	cout << id << ": Введите первую букву должности сотрудника: ";
	char position_char;
	cin >> position_char;
	switch (position_char)
	{
	case 'l': position_num = laborer; break;
	case 's': position_num = secretary; break;
	case 'm': position_num = manager; break;
	case 'a': position_num = accountant; break;
	case 'e': position_num = executive; break;
	case 'r': position_num = researcher;
	}
	cout << id << ": Введите дату трудоустройства (xx/xx/xxxx): ";
	employment_date.getdate();
	cout << id << ": Введите сумму оклада: ";
	cin >> benefit;
}

void employee::display() const
{
	if (!istablecreated)
		create_table();
	string position_str;
	switch (position_num)
	{
	case 0: position_str = "laborer"; break;
	case 1: position_str = "secretary"; break;
	case 2: position_str = "manager"; break;
	case 3: position_str = "accountant"; break;
	case 4: position_str = "executive"; break;
	case 5: position_str = "researcher";
	}
	cout << setw(9) << number << setw(6) << id << setw(12) << position_str << "   ";
	employment_date.display();
	cout << fixed << setprecision(2) << setw(10) << benefit << endl;
	number++;
}

int main()
{
	SetConsoleOutputCP(1251);
	const employee worker1, worker2, worker3;
	worker1.display();
	worker2.display();
	worker3.display();
	return 0;
}
