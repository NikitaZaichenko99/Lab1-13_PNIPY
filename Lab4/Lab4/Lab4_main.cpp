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
	//������ � ������� Triad
	cout << "������ � ������� Triad:";
	Triad a;
	cin >> a; ++a;
	cout << a;
	Triad b(10, 86, 115); ++b;
	cout << b;
	if(a==b){ cout << endl << "��������� ���������� a � b �����"; }
	else{ cout << endl << "��������� ���������� a � b �� �����"; }
	if(a != b){ cout << endl << "��������� ���������� a � b �� �����" << endl;}
	else{ cout << endl << "��������� ���������� a � b �����" << endl; }
	//������ � ������� Time
	cout << endl << "������ � ������� Time:";
	Time c;
	cin >> c; ++c;
	cout << c;
	Time d(10, 86, 115); ++d;
	cout << d;
	if (c > d) { cout << endl << "��������� ���������� c ������ d"; }
	else { cout << endl << "��������� ���������� c ������ d"; }
	if (c < d) { cout << endl << "��������� ���������� c ������ d" << endl; }
	else { cout << endl << "��������� ���������� c ������ d" << endl; }
	if (c >= d) { cout << "��������� ���������� c ������ ��� ����� d"; }
	else { cout  << "��������� ���������� c ������ d"; }
	if (c <= d) { cout << endl << "��������� ���������� c ������ ��� ����� d" << endl; }
	else { cout << endl << "��������� ���������� c ������ d" << endl; }
	//������� �����������
	cout << endl << "������� �����������: ";
	f1(c);//�������� ������ ������ Lorry
	a = f2();//������� � ������� ������ ������ Lorry
	cout << endl;
}
