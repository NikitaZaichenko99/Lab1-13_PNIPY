#include "Employee.h"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

//функция для возврата объекта как результата
Employee make_tovar()
{
	string name;
	string post;
	double zarplata;
	cout << endl << "Введите ФИО: ";
	getline(cin, name);
	cout << endl << "Введите должность: ";
	getline(cin, post);
	cout << endl << "Введите зароботную плату: ";
	cin >> zarplata;
	Employee t(name, post, zarplata);
	return t;
}
//функция для передачи объекта как параметра
void print_tovar(Employee t)
{
	t.show();
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//конструктор без параметров
	Employee t1;
	t1.show();
	//коструктор с параметрами
	Employee t2("Алексеев Алексей Алексеевич","Инженер - технолог", 90000);
	t2.show();
	//конструктор копирования
	Employee t3 = t2;
	t3.set_name("Иванов Иван Иваныч");
	t3.set_post("Слесарь КИПиА");
	t3.set_zarplata(50000.0);
	//конструктор копирования
	print_tovar(t3);
	//конструктор копирования
	t1 = make_tovar();
	t1.show();
}
