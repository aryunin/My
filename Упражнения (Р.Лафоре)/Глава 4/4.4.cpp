#include <iostream>
#include <iomanip>
using namespace std; 

struct employee
{
	int id;
	float benefit;
};

int main()
{
	setlocale(LC_ALL, "Rus");
	employee worker1, worker2, worker3;
	cout << "Введите номер и пособие первого сотрудника: ";
	cin >> worker1.id >> worker1.benefit;
	cout << "Введите номер и пособие второго сотрудника: ";
	cin >> worker2.id >> worker2.benefit;
	cout << "Введите номер и пособие третьего сотрудника: ";
	cin >> worker3.id >> worker3.benefit;

	cout << setw(10) << "Сотрудник" << setw(10) << "Номер" << setw(10) << "Пособие" << endl
		<< setw(10) << 1 << setw(10) << worker1.id << setw(10) << worker1.benefit << endl
		<< setw(10) << 2 << setw(10) << worker2.id << setw(10) << worker2.benefit << endl
		<< setw(10) << 3 << setw(10) << worker3.id << setw(10) << worker3.benefit << endl;
}
