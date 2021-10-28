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

class ship
{
private:
	static int ships_count;
	int ship_number;
	angle longitude, latitude;
public:
	ship() : ship_number(++ships_count)
	{ }
	void getShipCoords();
	void display() const
	{
		cout << "Корабль номер: " << ship_number << " находится в точке: "; 
		longitude.display(); cout << ", "; latitude.display(); cout << endl;
	}
};

int ship::ships_count = 0;

void ship::getShipCoords()
{
	cout << "Корабль №" << ship_number << ":\n";
	cout << "Введите координаты долготы (x\xB0y\' N/S/W/E): ";
	longitude.getangle();
	cout << "Введите координаты широты (x\xB0y\' N/S/W/E): ";
	latitude.getangle();
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	ship ship1, ship2, ship3;
	ship1.getShipCoords();
	ship2.getShipCoords();
	ship3.getShipCoords();
	ship1.display();
	ship2.display();
	ship3.display();
	return 0;
}
