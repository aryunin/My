#include <iostream>
using namespace std;

const float PI = 3.14159F;

float circarea(float rad);

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите радиус окружности: ";
	float rad;
	cin >> rad; 
	cout << "Площадь: " << circarea(rad);
}


float circarea(float rad)
{
	return PI * rad* rad;
}