#include "pch.h"
#include <iostream>
using namespace std;

struct Distance
{
	int feet;
	float inches;
};

struct Volume
{
	Distance height;
	Distance length;
	Distance width;
};

int main()
{
	float l, w, h, volume;
	Volume room{ {1, 2.3},{2, 2.4},{3, 2.5} };
	l = room.length.inches + room.length.feet * 12;
	w = room.width.inches + room.width.feet * 12;
	h = room.height.inches + room.height.feet * 12;
	volume = l*w*h;
	cout << volume; 
	return 0;
}