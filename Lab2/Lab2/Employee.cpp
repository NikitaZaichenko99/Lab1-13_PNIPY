#include "Employee.h"
#include <iostream>
#include <string>

using namespace std;

//����������� ��� ����������
Employee::Employee()
{
	name = "";
	post = "";
	zarplata = 0;
	cout << endl << "����������� ��� ���������� ��� �������: " << this << endl;
}
//����������� � �����������
Employee::Employee(string Name, string Post, double Zarplata)
{
	name = Name;
	post = Post;
	zarplata = Zarplata;
	cout << endl << "����������� � ���������� ��� �������: " << this << endl;
}
//����������� �����������
Employee::Employee(const Employee& t)
{
	name = t.name;
	post = t.post;
	zarplata = t.zarplata;
	cout << endl << "����������� ����������� ��� �������: " << this << endl;
}
//����������
Employee::~Employee()
{
	cout << endl << "���������� ��� �������: " << this << endl;
}
//���������
string Employee::get_name()
{
	return name;
}
string Employee::get_post()
{
	return post;
}
double Employee::get_zarplata()
{
	return zarplata;
}
//������������
void Employee::set_name(string newName)
{
	name = newName;
}
void Employee::set_post(string newPost)
{
	post = newPost;
}
void Employee::set_zarplata(double newZarplata)
{
	zarplata = newZarplata;
}
//����� ��� ��������� ���������
void Employee::show()
{
	cout << endl;
	cout << "���: " << name << endl;
	cout << "���������: " << post << endl;
	cout << "��������: " << zarplata << endl;
}