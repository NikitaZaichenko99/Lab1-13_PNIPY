#include "Triad.h"
#include "Time.h"

void f1(Time& c)
{
	c.Set_hours(45);
	cout << c;
}
Triad f2()
{
	Time l(12, 24, 35);
	cout << l;
	return l;
}
void main()
{
	setlocale(LC_ALL, "Russian");
	//работа с классом Triad
	cout << "Работа с классом Triad:";
	Triad a;
	cin >> a; ++a;
	cout << a;
	Triad b(10, 86, 115); ++b;
	cout << b;
	if(a==b){ cout << endl << "Временные промежутки a и b равны"; }
	else{ cout << endl << "Временные промежутки a и b не равны"; }
	if(a != b){ cout << endl << "Временные промежутки a и b не равны" << endl;}
	else{ cout << endl << "Временные промежутки a и b равны" << endl; }
	//работа с классом Time
	cout << endl << "Работа с классом Time:";
	Time c;
	cin >> c; ++c;
	cout << c;
	Time d(10, 86, 115); ++d;
	cout << d;
	if (c > d) { cout << endl << "Временной промежуток c больше d"; }
	else { cout << endl << "Временной промежуток c меньше d"; }
	if (c < d) { cout << endl << "Временной промежуток c меньше d" << endl; }
	else { cout << endl << "Временной промежуток c больше d" << endl; }
	if (c >= d) { cout << "Временной промежуток c больше или равен d"; }
	else { cout  << "Временной промежуток c меньше d"; }
	if (c <= d) { cout << endl << "Временной промежуток c меньше или равен d" << endl; }
	else { cout << endl << "Временной промежуток c больше d" << endl; }
	//принцип подстановки
	cout << endl << "Принцип подстановки: ";
	f1(c);//передаем объект класса Lorry
	a = f2();//создаем в функции объект класса Lorry
	cout << endl;
}
