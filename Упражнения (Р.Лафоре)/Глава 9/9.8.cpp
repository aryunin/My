#include <iostream>
#include <Windows.h>
//#include <cstring>
using namespace std;

class String
{
protected:
    enum { SZ = 80 }; // размер массива
    char str[SZ]; // массив для хранения строки
public:
    // конструктор без параметров
    String()
    {
        str[0] = '\x0';
    }
    // конструктор с одним параметром
    String(const char s[])
    {
        strcpy_s(str, s);
    } // сохраняем строку в массиве
// показ строки
    void display() const
    {
        cout << str;
    }
    // перевод строки к обычному типу
    operator char* ()
    {
        return str;
    }
};

class Pstring : public String
{
public:
    Pstring() : String()
    { }
    Pstring(const char[]);
    void left(Pstring, unsigned int);
    void mid(Pstring, unsigned int, unsigned int);
    void right(Pstring, unsigned int);
    void clear()
    { str[0] = '\x0'; }
};

Pstring::Pstring(const char s[])
{
    if (strlen(s) + 1 > SZ - 1)
    {
        for (int i = 0; i < SZ - 1; i++)
            str[i] = s[i];
        str[SZ - 1] = '\0';
    }
    else strcpy_s(str, s);
}

void Pstring::left(Pstring s, unsigned int count)
{
    clear();

    if(count > SZ - 1)
    { 
        cerr << "Ошибка: количество символов для копирования превышает максимальное допустимое число!\n";
        exit(1);
    }

    strncpy_s(str, s, count);
    str[count] = '\0';
}

void Pstring::mid(Pstring s, unsigned int from, unsigned int count)
{
    clear();

    if (count > SZ - from - 1)
    {
        cerr << "Ошибка: количество символов для копирования превышает максимальное допустимое число!\n";
        exit(1);
    }

    for (unsigned int i = 0; i < count; i++)
            str[i] = s[from + i];
    str[count] = '\0';
}

void Pstring::right(Pstring s, unsigned int count)
{
    clear();

    if (count > SZ - 1)
    {
        cerr << "Ошибка: количество символов для копирования превышает максимальное допустимое число!\n";
        exit(1);
    }

    for (unsigned int i = 0; i < count; i++)
        str[i] = s[strlen(s)-count+i];
    str[count] = '\0';
}

// --------------- main() ---------------- 
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    Pstring s1;
    s1.left("Как дела?", 5);
    s1.display();
    cout << endl;

    Pstring s2;
    s2.mid("Как дела?", 2, 3);
    s2.display();
    cout << endl;

    Pstring s3;
    s3.right("Как дела?", 7);
    s3.display();
    cout << endl;



    return 0;
}
