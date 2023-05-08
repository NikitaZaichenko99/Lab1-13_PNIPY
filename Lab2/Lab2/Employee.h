#pragma once
#include <iostream>
#include <string>
using namespace std;

class Employee
{
	//атрибуты
	string name;
	string post;
	double zarplata;

public:
	Employee();//конструктор без параметров
	Employee(string, string, double);//конструктор с параметрами
	Employee(const Employee&);//конструктор копирования
	~Employee();//деструктор
	string get_name();//селектор
	void set_name(string);//модификатор
	string get_post();//селектор
	void set_post(string); //модификатор
	double get_zarplata();//селектор
	void set_zarplata(double); //модификатор
	void show();//просмотр атрибутов
};