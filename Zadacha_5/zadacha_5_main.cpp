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
	cout << "������������ ������� = " << m << endl;
	v.Add(m);
	v.Print();
	cout << "������� ����� � ������� ��� �����: " << endl;
	cin >> r; cin >> c;
	Money q(r, c);
	s = v.removeByKey(q);
	cout << "������� " << s << " ������" << endl;
	v.Print();
	t = v.Srednee();
	cout << "������� �������� = " << t << endl;
	v.Add_srednee(t);
	v.Print();
}