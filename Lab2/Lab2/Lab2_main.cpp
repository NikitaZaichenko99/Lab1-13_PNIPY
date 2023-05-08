#include "Employee.h"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

//������� ��� �������� ������� ��� ����������
Employee make_tovar()
{
	string name;
	string post;
	double zarplata;
	cout << endl << "������� ���: ";
	getline(cin, name);
	cout << endl << "������� ���������: ";
	getline(cin, post);
	cout << endl << "������� ���������� �����: ";
	cin >> zarplata;
	Employee t(name, post, zarplata);
	return t;
}
//������� ��� �������� ������� ��� ���������
void print_tovar(Employee t)
{
	t.show();
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//����������� ��� ����������
	Employee t1;
	t1.show();
	//���������� � �����������
	Employee t2("�������� ������� ����������","������� - ��������", 90000);
	t2.show();
	//����������� �����������
	Employee t3 = t2;
	t3.set_name("������ ���� ������");
	t3.set_post("������� �����");
	t3.set_zarplata(50000.0);
	//����������� �����������
	print_tovar(t3);
	//����������� �����������
	t1 = make_tovar();
	t1.show();
}
