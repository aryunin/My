#include <iostream>
using namespace std;

struct time
{
	int hours;
	int minutes;
	int seconds;
};

long time_to_secs(time tt);
time secs_to_time(long secs);

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
	t_sum = secs_to_time(time_to_secs(t1) + time_to_secs(t2));
	cout << "Суммированное значение времени: " << t_sum.hours << dummychar << t_sum.minutes << dummychar << t_sum.seconds << endl;
	return 0;
}

long time_to_secs(time tt)
{
	return tt.hours * 3600 + tt.minutes * 60 + tt.seconds;
}

time secs_to_time(long secs)
{
	time tt;
	tt.hours = secs / 3600;
	secs %= 3600;
	tt.minutes = secs / 60;
	tt.seconds = secs % 60;
	return tt;
}