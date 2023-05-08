#include "Money.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);//������� ��� ������
	if (!stream) return -1;//������ �������� �����
	int n;
	Money m;
	cout << "������� ���������� ��������\n"; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m; ++m;//���� ��������� ������� �� ������������ ������ 
		stream << m << "\n";//������ ������� � �������� �����
	}
	stream.close();//������� �����
	return n;//������� ���������� ���������� ��������
}
int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);//������� ��� ������
	if (!stream)return -1;//������ �������� �����
	Money m; int i = 0;
	while (stream >> m)
	{
		cout << m << "\n";
		i++;
	}
	stream.close();
	return i;
}
int del_file(const char* f_name, int r, int c)
{
	fstream temp("temp", ios::out);//������� ��� ������
	fstream stream(f_name, ios::in);//������� ��� ������
	if (!stream)return -1;//������ �������� �����
	int i = 0; Money m;
	while (stream >> m)//���� ��� ����� ����� ��������� ������ �������
	{
		//���� �������� ������� ����� �����,�� ����� �� �����
		if (stream.eof())break;
		i++;
		if (m.get_rub() != r && m.get_cop() != c)
			temp << m;
	}
	//������� �����
	stream.close(); temp.close();
	remove(f_name);//������� ������ ����
	rename("temp", f_name);// ������������� temp
	return i;//���������� �����������
}
int add_file(const char* f_name, int r, int c, Money pp)
{
	fstream temp("temp", ios::out);//������� ��� ������
	fstream stream(f_name, ios::in);//������� ��� ������
	if (!stream) return -1;//������ �������� �����
	Money m; int i = 0, l = 0;
	while (stream >> m)
	{
		if (stream.eof()) break;
		i++;
		temp << m; //�������� ������� ������ � temp
		if (m.get_rub() == r && m.get_cop() == c)
		{
			temp << pp; //�������� ����� ������ ����� ������� ������
			l++;
		}
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;//���������� �����������
}
int add_end(const char* f_name, Money pp)
{
	fstream stream(f_name, ios::app);//������� ��� ����������
	if (!stream)return -1;//������ �������� �����
	stream << pp; //�������� ����� ������
	return 1;
}
int change_file(const char* f_name, int r, int c, Money pp)
{
	fstream temp("temp", ios::out);//������� ��� ������
	fstream stream(f_name, ios::in);//������� ��� ������
	if (!stream)return -1;//������ �������� �����
	Money m; int i = 0, l = 0;
	/*char x;*/
	while (stream >> m)
	{
		if (stream.eof())break;
		i++;
		if (m.get_rub() == r && m.get_cop() == c)
		{
			m = m - pp;
			temp << m;
			if (m.get_rub() < 0) m.set_rub(0);
			if (m.get_cop() < 0) m.set_cop(0);
			l++;
		}
		else temp << m;
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;//���������� ���������� ���������
}