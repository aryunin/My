#include "pch.h"
#include <iostream>
using namespace std;

struct point
{
	int x;
	int y;
};

int main()
{
	setlocale(LC_ALL, "Rus");
	point point1, point2, point3;
	cout << "Введите координаты point1 через пробел: ";
	cin >> point1.x >> point1.y;
	cout << "Введите координаты point2 через пробел: ";
	cin >> point2.x >> point2.y;
	point3.x = point1.x + point2.x;
	point3.y = point1.y + point2.y;
	cout << "Координаты точки point1 + point2: " << point3.x << ' ' << point3.y;
	return 0;
}