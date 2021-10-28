#include <iostream>
#include <Windows.h>
using namespace std;

class matrix
{
private:
	static const int X = 10, Y = 10;
	int mat[X][Y];
	int realX;
	int realY;
public:
	matrix(int x, int y)
	{
		if (x < 2 || y < 2)
		{
			cerr << "Ошибка: минимальный размер матрицы - 2x2\n";
			exit(1);
		}
		else if (x > 10 || y > 10)
		{
			cerr << "Ошибка: максимальный размер матрицы - 10x10\n";
			exit(1);
		}
		else
		{
			realX = x;
			realY = Y;
			for (int i = 0; i < realX; i++)
				for (int j = 0; j < realY; j++)
					mat[i][j] = 0;
		}
	}
	void putel(int x, int y, int var)
	{
		if (x < 0 || y < 0 || x > realX - 1 || y > realY - 1)
		{
			cerr << "Ошибка: выход за границы массива (матрицы)\n";
			exit(1);
		}
		else
			mat[x][y] = var;
	}
	int getel(int x, int y) const
	{
		if (x < 0 || y < 0 || x > realX - 1 || y > realY - 1)
		{
			cerr << "Ошибка: выход за границы массива (матрицы)\n";
			exit(1);
		}
		else
			return mat[x][y];
	}
};

const int matrix::X;
const int matrix::Y;

int main()
{
	SetConsoleOutputCP(1251);
	matrix m1(1, 4);
	int temp = 12345;
	m1.putel(2, 3, temp);
	cout << m1.getel(0, -1);
	return 0;
}
