#include "Triad.h"
#include "Time.h"
#include "Object.h"
#include "Vector.h"

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
	//������ � Vector
	cout << endl << "������ c Vector:";
	Vector v(5);//������ �� 5 ���������
	Triad f;//������ ������ Triad
	cin >> f; ++f;
	Time g;// ������ ������ Time
	cin >> g; ++g;
	Object* p = &f;//������ ��������� �� ������ ������ Triad
	v.Add(p);//��������� ������ � ������
	p = &g;//������ ��������� �� ������ ������ Time
	v.Add(p); //��������� ������ � ������
	cout << v;//����� �������

}
