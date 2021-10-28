#include <iostream>
using namespace std;  

enum etype { laborer, secretary, manager, accountant, executive, researcher };

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите первую букву должности\n(laborer, secretary, manager, accountant,\nexecutive, researcher): ";
	char letter;
	cin >> letter;
	etype position_num;
	string position_str;
	switch (letter)
	{
	case 'l': position_num = laborer; break;
	case 's': position_num = secretary; break;
	case 'm': position_num = manager; break;
	case 'a': position_num = accountant; break;
	case 'e': position_num = executive; break;
	case 'r': position_num = researcher;
	}
	switch (position_num)
	{
	case 0: position_str = "laborer"; break;
	case 1: position_str = "secretary"; break;
	case 2: position_str = "manager"; break;
	case 3: position_str = "accountant"; break;
	case 4: position_str = "executive"; break; 
	case 5: position_str = "researcher";
	}
	cout << position_str << endl;
}
