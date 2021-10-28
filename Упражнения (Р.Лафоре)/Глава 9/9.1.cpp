#include <iostream>
#include <Windows.h>
using namespace std;

// ---------- Class publication ---------- 
class publication
{
protected:
    string title;
    float cost;
public:
    publication() : title("N/A"), cost(0)
    { }
    /*publication(string n, float c) : name(n), cost(c)
    { }*/
    void getdata();
    void putdata() const;
};

void publication::getdata()
{
    cout << "Введите название книги: ";
    cin >> title;
    cout << "Введите цену книги: ";
    cin >> cost;
}
void publication::putdata() const
{
    cout << "Книга: \"" << title << "\"\tЦена: " << cost;
}
// ---------------------------------------

// ------------- Class book -------------- 
class book : public publication
{
private:
    int pages;
public:
    book() : publication(), pages(0) 
    { }
    void getdata();
    void putdata() const;
};

void book::getdata()
{
    publication::getdata();
    cout << "Введите количество страниц: ";
    cin >> pages;
}
void book::putdata() const
{
    publication::putdata();
    cout << "\tКол-во страниц: " << pages << endl;
}
// ---------------------------------------

// ------------- Class type -------------- 
class tape : public publication
{
private:
    float rec_time;
public:
    tape() : publication(), rec_time(float(0.0))
    { }
    void getdata();
    void putdata() const;
};

void tape::getdata()
{
    publication::getdata();
    cout << "Введите время записи: ";
    cin >> rec_time;
}
void tape::putdata() const
{
    publication::putdata();
    cout << "\tВремя записи: " << rec_time << endl;
}
// ---------------------------------------

// --------------- main() ---------------- 
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "\tТест класса бумажной книги: " << endl;
    book tb;
    tb.getdata();
    tb.putdata();

    cout << "\n\tТест класса  аудиокниги: " << endl;
    tape ab;
    ab.getdata();
    ab.putdata();
    return 0;
}
