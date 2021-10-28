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
};

Pstring::Pstring(const char s[])
{
    if (strlen(s) > SZ - 1)
    {
        for (int i = 0; i < SZ - 1; i++)
            str[i] = s[i];
    }
    else strcpy_s(str, s);
    str[SZ - 1] = '\0';
}

// --------------- main() ---------------- 
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    Pstring s1;
    s1.display();

    Pstring s2("Short text\n");
    s2.display();

    Pstring s3("Эта строка имеет очень большую длину и мы можем быть уверены, что она не уместится в отведенный буфер, что приведет к непредсказуемым последствиям.\n");
    s3.display();

    return 0;
}
