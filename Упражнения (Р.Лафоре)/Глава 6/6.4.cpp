#include <iostream>
#include <iomanip>
using namespace std;

class employee
{
private:
	static int number;
	int id;
	float benefit;
public:
	employee()
	{ 
		cout << "Введите номер и пособие сотрудника: ";
		cin >> id >> benefit;
	}
	void display() const
	{
		cout << setw(10) << number << setw(10) << id << setw(10) << benefit << endl;
		number++;
	}
};

int employee::number = 1;

void create_table();

int main()
{
	setlocale(LC_ALL, "Rus");
	const employee worker1, worker2, worker3;
	create_table();
	worker1.display();
	worker2.display();
	worker3.display();
	return 0;
}

void create_table()
{
	cout << setw(10) << "Сотрудник" << setw(10) << "Номер" << setw(10) << "Пособие" << endl;
}