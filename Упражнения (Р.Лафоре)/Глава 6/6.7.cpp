#include <iostream>
#include <Windows.h>
using namespace std;

class angle
{
private:
	int degreez;
	float minutes;
	char direction;
public:
	angle() : degreez(1), minutes(0.0), direction('N')
	{ }
	angle(int _degreez, float _minutes, char _direction) : degreez(_degreez), minutes(_minutes), direction(_direction)
	{ }
	void getangle()
	{
		cin >> degreez >> minutes >> direction;
	}
	void display() const
	{
		cout << degreez << '\xB0' << minutes << "\' " << direction;
	}
};

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	const angle angle1(5, 43.9F, 'S');
	angle1.display();
	char response;
	cout << endl;
	do
	{
		angle customangle;
		customangle.getangle();
		customangle.display();
		cout << "\nЖелаете продолжить?(Д/Н): ";
		cin >> response;
	} while (response == 'Д');
	return 0;
}
