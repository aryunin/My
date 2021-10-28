#include "Distance.h"

Distance Distance::operator+(Distance d2) const
{
	int f = feet + d2.feet; // складываем футы
	float i = inches + d2.inches; // складываем дюймы
	if (i >= 12.0) // если дюймов стало больше 12
	{
		i -= 12.0; // то уменьшаем дюймы на 12
		f++; // и увеличиваем футы на 1
	}
	return Distance(f, i); // создаем и возвращаем временную переменную
}

Distance Distance::operator-(Distance d2) const
{
	int f = feet - d2.feet; // вычитаем футы
	float i = inches - d2.inches; // вычитаем дюймы
	if (i < 0.0) // если дюймов стало меньше 0
	{
		i += 12.0; // то увеличиваем дюймы на 12
		f--; // и уменьшаем футы на 1
	}
	return Distance(f, i); // создаем и возвращаем временную переменную
}

