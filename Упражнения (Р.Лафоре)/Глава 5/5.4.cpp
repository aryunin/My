#include <iostream>
using namespace std;

struct Distance
{
	int feet;
	float inches;
};

inline float feet_to_inches(int feet);
Distance distance_compare(Distance dd1, Distance dd2);


int main()
{
	setlocale(LC_ALL, "Rus");
	Distance distance_first{ 2, 11 };
	Distance distance_second{ 3, 0 };
	Distance distance_greater = distance_compare(distance_first, distance_second);
	if (distance_greater.feet < 0)
		cout << "Значения " << distance_first.feet << "\'-" << distance_first.inches << "\" и "
		<< distance_second.feet << "\'-" << distance_second.inches << "\" равны\n";
	else
		cout << "Большее значение " << distance_greater.feet << "\'-" << distance_greater.inches << "\"\n";
	return 0;
}

inline float feet_to_inches(int feet)
{
	return feet * 12.0F;
}

Distance distance_compare(Distance dd1, Distance dd2)
{
	float inches_first = feet_to_inches(dd1.feet) + dd1.inches;
	float inches_second = feet_to_inches(dd2.feet) + dd2.inches;
	if (inches_first > inches_second)
		return dd1;
	else if (inches_first < inches_second)
		return dd2;
	else
		return { -1,0 };
}
