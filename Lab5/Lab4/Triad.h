#pragma once
#include <iostream>
#include "object.h"

using namespace std;

class Triad :
	public Object
{
public:
	Triad(void); //конструктор без параметров
public:
	virtual ~Triad(void); 	//деструктор
	void Show(); //функция для просмотра атрибутов класса с помощью указателя
	Triad(int, int, int); //констрктор с параметрами
	Triad(const Triad&); //конструктор копирования
	int Get_first() { return first; } //селектор
	int Get_second() { return second; } //селектор
	int Get_third() { return third; } //селектор
	void Set_first(int); //модификатор
	void Set_second(int); //модификатор
	void Set_third(int); //модификатор
	Triad& operator++(); //перегрузка префиксной операции
	Triad& operator=(const Triad&); //перегрузка операции присваивания
	bool operator==(const Triad& l); //перегрузка операции сравнения
	bool operator!=(const Triad& l); //перегрузка операции сравнения
	friend istream& operator>>(istream& in, Triad& c); //операция ввода
	friend ostream& operator<<(ostream& out, const Triad& c); //операция вывода
protected: //атрибуты
	int first;
	int second;
	int third;
};

