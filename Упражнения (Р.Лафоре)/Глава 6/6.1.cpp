#include <iostream>
using namespace std;

class Int
{
private: 
	int value;
public: 
	Int() : value(0)
	{ }
	Int(int _value) : value(_value)
	{ }
	void showint() const
	{ cout << value << endl; }
	Int addint(const Int& _value) const;
};

int main()
{
	setlocale(LC_ALL, "Rus");
	const Int value1(23), value2(27); 
	Int value3 = value1.addint(value2);
	value3.showint();
	return 0;
}

Int Int::addint(const Int& _value) const
{
	Int tmp = value + _value.value;
	return tmp;
}
