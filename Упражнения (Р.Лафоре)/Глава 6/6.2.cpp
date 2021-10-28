#include <iostream>
#include <conio.h>
using namespace std;

const char ESC = 27;	
const double TOLL = 0.5;	

class tollBooth 
{
private:
	unsigned int count;
	double revenue;
public:
	tollBooth() : count(0), revenue(0.0)
	{ }
	void payingCar()
	{
		count++;
		revenue += TOLL;
	}
	void nopayCar() { count++; }
	void display() const { cout << "\nСCount: " << count << ", revenue: " << revenue << endl; }
};

int main() 
{
	tollBooth booth1;
	char response;
	cout << "'+' - payingCar, '-' - nopayCar, 'ESC' - exit: ";
	while ((response = _getche()) != ESC)
	{
		if (response == 43)
			booth1.payingCar();
		else if (response == 45)
			booth1.nopayCar();
	} 
	booth1.display();
	return 0;
}