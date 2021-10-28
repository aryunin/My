#include <iostream>
#include <windows.h>
using namespace std;

class employee
{
private:
	string name;
	long number;
public:
	void getdata()
	{
		cin >> name >> number;
	}
	void putdata() const
	{
		cout << "Имя: " << name << ", номер: " << number << endl;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int MAX = 100;
	employee person[MAX];
	int i = -1;

	char response;
	do {
		i++;
		cout << "Введите имя и номер служащего через пробел: ";
		person[i].getdata();
		cout << "Желаете продолжить?(y/n): ";
		cin >> response;
	} while (i < MAX && response != 'n');

	while (i >= 0)
	{
		person[i].putdata();
		i--;
	}
	return 0;
}

