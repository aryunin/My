#include <iostream>
using namespace std;

inline long hms_to_secs(int hours, int minutes, int seconds);

int main()
{
	setlocale(LC_ALL, "Rus");
	int hours, minutes, seconds;
	char ch;
	do
	{
		cout << "Введите значение врмемени (ЧЧ:ММ:СС): ";
		cin >> hours >> ch >> minutes >> ch >> seconds;
		cout << "Эквивалент времени в секундах: " << hms_to_secs(hours, minutes, seconds) << endl
			<< "Чтобы попробовать ещё, введите Y: ";
		cin >> ch;
	} while (ch == 'Y');
	return 0;
}

inline long hms_to_secs(int hours, int minutes, int seconds)
{
	return hours * 3600 + minutes * 60 + seconds;
}
