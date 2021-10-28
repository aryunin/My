#include <iostream>
using namespace std;

struct time
{
	int hours, minutes, seconds;
};

void swap(time& t1, time& t2);

int main()
{
	setlocale(LC_ALL, "Rus");
	time t1, t2;
	char dummychar;
	cout << "Введите первое значение времени в формате <hh:mm:ss>: ";
	cin >> t1.hours >> dummychar >> t1.minutes >> dummychar >> t1.seconds;
	cout << "Введите второе значение времени в формате <hh:mm:ss>: ";
	cin >> t2.hours >> dummychar >> t2.minutes >> dummychar >> t2.seconds;
	swap(t1, t2);
	cout << "Значения времени поменяны местами.\nПервое значение времени: " << t1.hours << dummychar << t1.minutes << dummychar << t1.seconds
		<< "\nВторое значение времени: " << t2.hours << dummychar << t2.minutes << dummychar << t2.seconds << endl;
	return 0;
}

void swap(time& t1, time& t2)
{
	time tmp = t1;
	t1 = t2;
	t2 = tmp;
}
