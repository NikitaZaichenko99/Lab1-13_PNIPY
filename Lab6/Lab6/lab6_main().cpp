#include "Set.h"
#include "iostream"

void main()
{
	setlocale(LC_ALL, "Russian");
	int n, k, l, j, s;
	Set a(5);
	cout << "��������� a: " << endl;
	cout << a << endl;
	cin >> a;
	cout << "��������� a: " << endl;
	cout << a << endl;
	cout << "������� ������� ������ ������ ��������: " << endl;
	cin >> n;
	cout << "������� ����� ��������: " << endl;
	cin >> k;
	a[n - 1] = k;
	cout << "��������� a: " << endl;
	cout << a << endl;
	Set b(10);
	cout << "��������� b �� 10 ���������: " << endl;
	cout << b << endl;
	b = a;
	cout << "��������� ��������� b �������� ������� a: " << endl;
	cout << b << endl;
	Set c(10); 
	c = b + 100;
	cout << "C������ ��������� c �� 10 ��������� � ��������� �� 100: " << endl;
	cout << c << endl;
	cout << endl << "����� ��������� a = " << a() << endl;
	cout << endl << "��������� ����������� ������� � ������� �������� ��������� a: ";
	cout << endl << a[0] << " != " << a[1] << endl;
	if (a[0] != a[1]) { cout << "�������� �� �����" << endl; } 
	else { cout << "�������� �����" << endl; }
	cout << endl << "������� ������� ��� �������� �������������� ���������: ";
	cin >> l;
	if (a < l) { cout << "�������� ����������� ��������� a" << endl; }
	else { cout << "�������� �� ����������� ��������� a" << endl; }
	cout << "���������� ������ ������� ��������� a" << endl;
	cout << "������ �������: " << *(a.first()) << endl;
	Iterator i = a.first();
	cout << "������� ������ � �������� � ������� n, ������� n: " << endl;
	cin >> j;
	j = j - 1;
	Iterator d;
	d = i+j;
	cout << "������� � ������� n: " << *d;
}