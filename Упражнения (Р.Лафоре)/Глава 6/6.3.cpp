#include <iostream>
using namespace std;

class time
{
private:
	int hrs, mins, secs;
public:
	time() : hrs(0), mins(0), secs(0)
	{ }
	time(int _hrs, int _mins, int _secs) : hrs(_hrs), mins(_mins), secs(_secs)
	{ }
	void show() const
	{
		cout << hrs << ':' << mins << ':' << secs << endl; 
	}
	void time_add(time time1, time time2);
	void time_to_std();
};

int main()
{
	const time time1(21, 59, 59);
	const time time2(18, 59, 59);
	time time3; 
	time3.time_add(time1, time2);
	time3.show();
	return 0;
}

void time::time_add(time time1, time time2)
{
	hrs = time1.hrs + time2.hrs;
	mins = time1.mins + time2.mins;
	secs = time1.secs + time2.secs;
	time_to_std();
}

void time::time_to_std()
{
	if (secs >= 60)
	{
		secs -= 60;
		mins++;
	}
	if (mins >= 60)
	{
		mins -= 60;
		hrs++;
	}
}