#include <iostream>
#include <windows.h>
using namespace std;

class Distance
{
private:
	int feet;
	double inches;
public:
	Distance() : feet(0), inches(0.0)
	{ }
	void getdist() // получение информации
	{
		cout << "Введите футы: "; cin >> feet;
		cout << "Введите дюймы: "; cin >> inches;
	}
	void showdist() const 
	{
		cout << feet << "\'-" << inches << '\"';
	}
	void div_dist(Distance, int);
	void add_dist(Distance, Distance);
};

int main()
{
	SetConsoleOutputCP(1251);

	const int MAX = 100;
	Distance dist[MAX];
	int j = -1;

	char response;
	do
	{
		j++;
		dist[j].getdist();
		cout << "Желаете продолжить?(y/n): ";
		cin >> response;
	} while (j < MAX && response != 'n');

	Distance average = dist[0];
	for (int i = 1; i < j + 1; i++)
		average.add_dist(dist[i], average);
	average.div_dist(average, j + 1);
	
	average.showdist();
	return 0;
}

void Distance::div_dist(Distance d2, int divisor)
{
	double dblfeet = d2.feet + d2.inches / 12.0;
	double temp = dblfeet /= divisor;
	feet = int(dblfeet);
	inches = (temp - feet) * 12.0;
}

void Distance::add_dist(Distance dd1, Distance dd2)
{
	inches = dd1.inches + dd2.inches; 
	feet = 0; 
	if (inches >= 12.0) 
	{ 
		inches -= 12.0;
		feet++; 
	}
	feet += dd1.feet + dd2.feet; 
}
