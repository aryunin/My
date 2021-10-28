#include <iostream>
using namespace std;

class queue
{
private:
	static const int MAX = 3;
	int qu[MAX];
	int head, tail;
public:
	queue() 
	{
		head = 0;
		tail = 0;
	}
	void put(int var)
	{
		if (tail == MAX)
			tail = 0;
		qu[tail++] = var;
	}
	int get()
	{
		if (head == MAX)
			head = 0;
		return qu[head++];
	}
};

const int queue::MAX;

int main()
{
	queue qu1;
	qu1.put(22);
	qu1.put(32);
	qu1.put(44);
	for (int i = 0; i < 4; i++)
	{
		cout << qu1.get() << endl;
	}
	return 0;
}
