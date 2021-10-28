#include <iostream>
#include <Windows.h>
using namespace std;
const int LIMIT = 100; // размер массива
///////////////////////////////////////////////////////////
class safearray
{
private:
    int arr[LIMIT];
public:
    // обратите внимание, что функция возвращает ссылку!
    int& operator[](int n)
    {
        if (n < 0 || n >= LIMIT)
        {
            cout << "\nОшибочный индекс!"; exit(1);
        }
        return arr[n];
    }
};
///////////////////////////////////////////////////////////
class safehilo : public safearray
{
private:
    int min_index;
    int max_index;
public:
    safehilo() : min_index(0), max_index(99)
    { }
    safehilo(int low, int high) : min_index(low), max_index(high)
    { 
        if (max_index - min_index + 1 > LIMIT)
        {
            cerr << "Ошибка: введенные границы превышают допустимый размер массива в " << LIMIT << " элементов!\n";
            exit(2);
        }
    }
    int& operator[](int n)
    {
        if (n >= min_index && n <= max_index)
            safearray::operator[](n - min_index);
        else
        {
            cerr << "Ошибка: ошибочный индекс!\n";
            exit(1);
        }
    }
};
///////////////////////////////////////////////////////////
int main()
{
    SetConsoleOutputCP(1251);

    int min = -10;
    int max = 90;

    safehilo sa1(min, max);

    // задаем значения элементов
    for (int j = min; j <= max; j++)
        sa1[j] = j * 10; // используем функцию слева от знака =

    // показываем элементы
    for (int j = min; j <= max; j++)
    {
        int temp = sa1[j]; // используем функцию справа от знака =
        cout << "Элемент " << j << " равен " << temp << endl;
    }

    return 0;
}