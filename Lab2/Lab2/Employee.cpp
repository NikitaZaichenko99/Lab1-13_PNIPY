#include "Employee.h"
#include <iostream>
#include <string>

using namespace std;

//конструктор без параметров
Employee::Employee()
{
	name = "";
	post = "";
	zarplata = 0;
	cout << endl << "Конструктор без параметров для обьекта: " << this << endl;
}
//конструктор с параметрами
Employee::Employee(string Name, string Post, double Zarplata)
{
	name = Name;
	post = Post;
	zarplata = Zarplata;
	cout << endl << "Конструктор с параметром для обьекта: " << this << endl;
}
//конструктор копирования
Employee::Employee(const Employee& t)
{
	name = t.name;
	post = t.post;
	zarplata = t.zarplata;
	cout << endl << "Конструктор копирования для обьекта: " << this << endl;
}
//деструктор
Employee::~Employee()
{
	cout << endl << "Деструктор для обьекта: " << this << endl;
}
//селекторы
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
//модификаторы
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
//метод для просмотра атрибутов
void Employee::show()
{
	cout << endl;
	cout << "ФИО: " << name << endl;
	cout << "Должность: " << post << endl;
	cout << "Зарплата: " << zarplata << endl;
}