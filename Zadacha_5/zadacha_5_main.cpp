#include <C:\Users\nikit\source\repos\Zadacha_2\Money.h>
#include <iostream>
#include <stack>
#include <vector>
#include "Vector.h"

using namespace std;
void main()
{
	setlocale(LC_ALL, "rus");
	Money s, t;
	long r; int c;
	Vector<Money>v(3);
	v.Print();
	Money m = v.Max();
	cout << "Максимальный элемент = " << m << endl;
	v.Add(m);
	v.Print();
	cout << "Введите рубли и копейки для ключа: " << endl;
	cin >> r; cin >> c;
	Money q(r, c);
	s = v.removeByKey(q);
	cout << "Элемент " << s << " удален" << endl;
	v.Print();
	t = v.Srednee();
	cout << "Среднее значение = " << t << endl;
	v.Add_srednee(t);
	v.Print();
}