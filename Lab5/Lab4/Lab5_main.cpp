#include "Triad.h"
#include "Time.h"
#include "Object.h"
#include "Vector.h"

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
	//работа с Vector
	cout << endl << "Работа c Vector:";
	Vector v(5);//вектор из 5 элементов
	Triad f;//объект класса Triad
	cin >> f; ++f;
	Time g;// объект класса Time
	cin >> g; ++g;
	Object* p = &f;//ставим указатель на объект класса Triad
	v.Add(p);//добавляем объект в вектор
	p = &g;//ставим указатель на объект класса Time
	v.Add(p); //добавляем объект в вектор
	cout << v;//вывод вектора

}
