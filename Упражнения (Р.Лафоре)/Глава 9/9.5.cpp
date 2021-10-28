#include <iostream>
#include <Windows.h>
using namespace std;
const int LEN = 80; // максимальная длина имени
///////////////////////////////////////////////////////////
class employee // некий сотрудник
{
private:
    char name[LEN]; // имя сотрудника
    unsigned long number; // номер сотрудника
public:
    void getdata()
    {
        cout << "Введите фамилию: "; cin >> name;
        cout << "Введите номер: "; cin >> number;
    }
    void putdata() const
    {
        cout << "Фамилия: " << name;
        cout << "\nНомер: " << number;
    }
};
///////////////////////////////////////////////////////////
class manager : public employee // менеджер
{
private:
    char title[LEN]; // должность, например вице-президент
    double dues; // сумма взносов в гольф-клуб
public:
    void getdata()
    {
        employee::getdata();
        cout << "Введите должность: "; cin >> title;
        cout << "Введите сумму взносов в гольф-клуб: "; cin >> dues;
    }
    void putdata() const
    {
        employee::putdata();
        cout << "\nДолжность: " << title;
        cout << "\nСумма взносов в гольф-клуб: " << dues;
    }
};
///////////////////////////////////////////////////////////
class scientist : public employee // ученый
{
private:
    int pubs; // количество публикаций
public:
    void getdata()
    {
        employee::getdata();
        cout << "Введите количество публикаций: "; cin >> pubs;
    }
    void putdata() const
    {
        employee::putdata();
        cout << "\nКоличество публикаций: " << pubs;
    }
};
///////////////////////////////////////////////////////////
class laborer : public employee // рабочий
{
};
///////////////////////////////////////////////////////////
class compensation // рабочий
{
private:
    double value;
    enum class c_type {hourly, weekly, monthly} period;
public:
    compensation() : value(0.0), period(c_type::monthly)
    { }
    void getdata();
    void putdata() const;
};
void compensation::getdata()
{
    cout << "Введите размер оплаты: ";
    cin >> value;
    cout << "Введите период оплаты (hourly/weekly/monthly): ";
    string period_in;
    cin >> period_in;
    if (period_in == "hourly")
        period = c_type::hourly;
    else if (period_in == "weekly")
        period = c_type::weekly;
    else
        period = c_type::monthly;
}
void compensation::putdata() const
{
    cout << "\nОплата: " << value << ' ';
    string c_type_out;
    if (period == c_type::hourly)
        c_type_out = "почасовая";
    else if (period == c_type::weekly)
        c_type_out = "еженедельная";
    else
        c_type_out = "ежемесячная";
    cout << c_type_out << endl;
}
///////////////////////////////////////////////////////////
class manager2 : public manager, public compensation // менеджер with compensation
{
public:
    void getdata()
    {
        manager::getdata();
        compensation::getdata();
    }
    void putdata() const
    {
        manager::putdata();
        compensation::putdata();
    }
};
///////////////////////////////////////////////////////////
class scientist2 : public scientist, public compensation // ученый with compensation
{
public:
    void getdata()
    {
        scientist::getdata();
        compensation::getdata();
    }
    void putdata() const
    {
        scientist::putdata();
        compensation::putdata();
    }
};
///////////////////////////////////////////////////////////
class laborer2 : public laborer, public compensation // рабочий with compensation
{
public:
    void getdata()
    {
        laborer::getdata();
        compensation::getdata();
    }
    void putdata() const
    {
        laborer::putdata();
        compensation::putdata();
    }
};
///////////////////////////////////////////////////////////
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    manager2 m1, m2;
    /*scientist2 s1;
    laborer2 l1;*/

    // введем информацию о нескольких сотрудниках
    cout << "\tВвод информации о первом менеджере:\n";
    m1.getdata();
    cout << "\n\tВвод информации о втором менеджере:\n";
    m2.getdata();

    /*cout << "\n\tВвод информации о первом ученом:\n";
    s1.getdata();
    cout << "\n\tВвод информации о первом рабочем:\n";
    l1.getdata();*/

    // выведем полученную информацию на экран
    cout << "\n\tИнформация о первом менеджере:\n";
    m1.putdata();
    cout << "\n\tИнформация о втором менеджере:\n";
    m2.putdata();

    /*cout << "\n\tИнформация о первом ученом:\n";
    s1.putdata();
    cout << "\n\tИнформация о первом рабочем:\n";
    l1.putdata();*/

    return 0;
}