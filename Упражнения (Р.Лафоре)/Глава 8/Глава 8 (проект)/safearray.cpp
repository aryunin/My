#include "safearray.h"
#include <iostream>

safearray::safearray() : min_index(0), max_index(100)
{
	array_init();
}

safearray::safearray(unsigned int min_i, unsigned int max_i)
{
	if (max_i - min_i <= LIMIT)
	{
		min_index = min_i;
		max_index = max_i;
	}
	else
	{
		std::cerr << "Error: overflow!\n"; exit(1);
	}
	array_init();
}

int& safearray::operator[](unsigned int n)
{
	if (n < min_index || n >= max_index)
	{
		std::cout << "Wrong index!\n"; exit(2);
	}
	return arr[n - min_index];
}

void safearray::array_init()
{
	for (unsigned int i = 0; i < max_index - min_index; i++)
		arr[i] = 0;
}