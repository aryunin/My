#include <iostream>
using namespace std;

struct Time
{
	int hours;
	int minutes;
	int seconds;
};

int main()
{
	setlocale(LC_ALL, "Rus");
	Time time;
	char dummychar;
	cout << "Введите время в формате <hh:mm:ss>: ";
	cin >> time.hours >> dummychar >> time.minutes >> dummychar >> time.seconds;
	long totalsecs = time.hours * 3600 + time.minutes * 60 + time.seconds;
	cout << "Время в секундах: " << totalsecs << endl;
}