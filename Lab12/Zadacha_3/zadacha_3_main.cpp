#include <iostream>
#include "Container.h"
#include "Money.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");
	int n;
	Money m;
	cout << "N?"; cin >> n;
	Vector<Money> v(n, m);
	cin >> v;
	cout << "���������: " << v << endl;
	v.addMaxToEnd();
	cout << "�������� � ����� ������������ ��������: " << v << endl;
	Money k;
	cout << "������� ���� " << endl; cin >> k;
	v.removeByKey(k);
	cout << "������� ������� " << v << endl;
	v.addToEach();
	cout << "�������� ������� � ������� �������� " << v;
}
