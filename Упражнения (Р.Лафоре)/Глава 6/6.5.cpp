#include <iostream>
using namespace std;

class Date 
{ 
private:
	int day, mounth, year; 
	char dummychar;
public:
	Date() : day(1), mounth(1), year(2000)
	{ }
	void getdate()
	{
		cin >> day >> dummychar >> mounth >> dummychar >> year;
	}
	void showdate() const
	{
		cout << day << dummychar << mounth << dummychar << year << endl; 
	}
};

int main()
{
	Date date1;
	date1.getdate();
	date1.showdate();
	return 0;
}
