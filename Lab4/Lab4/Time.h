#pragma once
#include "Triad.h"

//класс Time наследуется от класса Triad
class Time :
	public Triad
{
public:
	Time(void);//конструктор без параметров
public:
	~Time(void);//деструктор
	Time(int, int, int);//конструктор с параметрами
	Time(const Time&); //конструктор копирования
	Time& operator++();
	Time& operator=(const Time&); //операция присваивания
	bool operator>(const Time& l); //перегрузка операции сравнения
	bool operator<(const Time& l); //перегрузка операции сравнения
	bool operator>=(const Time& l); //перегрузка операции сравнения
	bool operator<=(const Time& l); //перегрузка операции сравнения
	void Set_hours(int G); //модификатор
	void Set_minutes(int G); //модификатор
	void Set_seconds(int G); //модификатор
	int Get_hours() { return hours; } //селектор
	int Get_minutes() { return minutes; } //селектор
	int Get_seconds() { return seconds; } //селектор
	friend istream& operator>>(istream& in, Time& l);//операция ввода
	friend ostream& operator<<(ostream& out, const Time& l); //операция вывода
protected: //атрибуты
	int hours;
	int minutes;
	int seconds;
};

