#include <iostream>
using namespace std;

class safearay
{
private:
	static const int LIMIT = 10;
	int a[LIMIT];
public:
	void putel(unsigned int index, int value)
	{
		if (index < LIMIT - 1)
			a[index] = value;
		else cerr << "Ошибка: обращение к несуществующему элементу массива.";
	}
	int getel(unsigned int index)
	{
		if (index < LIMIT - 1)
			return a[index];
		else cerr << "Ошибка: обращение к несуществующему элементу массива.";
	}
};

const int safearay::LIMIT;

int main()
{
	safearay sa1;
	int temp = 12345; 
	sa1.putel(7, temp); 
	temp = sa1.getel(7);
	cout << temp;
	return 0;
}
