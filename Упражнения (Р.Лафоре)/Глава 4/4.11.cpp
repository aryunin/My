#include <iostream>
using namespace std;

struct time
{
	int hours;
	int minutes;
	int seconds;
};

int main()
{
	setlocale(LC_ALL, "Rus");
	time t1;
	time t2;
	time t_sum;
	char dummychar;
	cout << "Введите первое значение времени в формате <hh:mm:ss>: ";
	cin >> t1.hours >> dummychar >> t1.minutes >> dummychar >> t1.seconds;
	cout << "Введите второе значение времени в формате <hh:mm:ss>: ";
	cin >> t2.hours >> dummychar >> t2.minutes >> dummychar >> t2.seconds;
	long totalsecs1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
	long totalsecs2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
	long totalsecs_sum = totalsecs1 + totalsecs2;
	t_sum.hours = totalsecs_sum / 3600;
	totalsecs_sum %= 3600;
	t_sum.minutes = totalsecs_sum / 60;
	totalsecs_sum %= 60;
	t_sum.seconds = totalsecs_sum;
	cout << "Суммированное значение времени: " << t_sum.hours << dummychar << t_sum.minutes << dummychar << t_sum.seconds;
}