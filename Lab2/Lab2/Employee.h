#pragma once
#include <iostream>
#include <string>
using namespace std;

class Employee
{
	//��������
	string name;
	string post;
	double zarplata;

public:
	Employee();//����������� ��� ����������
	Employee(string, string, double);//����������� � �����������
	Employee(const Employee&);//����������� �����������
	~Employee();//����������
	string get_name();//��������
	void set_name(string);//�����������
	string get_post();//��������
	void set_post(string); //�����������
	double get_zarplata();//��������
	void set_zarplata(double); //�����������
	void show();//�������� ���������
};