#pragma once
#include <iostream>

using namespace std;

class Money
{
	long rub; int cop;

public:
	Money() { rub = 0; cop = 0; }; //конструктор без параметров
	Money(long r, int c) { rub = r; cop = c; } //конструктор с параметрами
	Money(const Money& m) { rub = m.rub; cop = m.cop; } //конструктор копирования
	~Money() {}; //деструктор
	int get_rub() { return rub; } //селектор
	int get_cop() { return cop; } //селектор
	void set_rub(long r) { rub = r; } //модификатор
	void set_cop(int c) { cop = c; } //модификатор
	Money& operator=(const Money& m);
	//перегруженные операции
	Money& operator++(); //перегрузка префиксной операции инкремент
	Money operator++(int); //постфиксная операция
	Money operator+(const Money&); //перегрузка бинарной операции сложения
	Money operator-(const Money&); //перегрузка бинарной операции вычитания
	bool operator==(const Money&); //перегрузка операции сравнения
	bool operator!=(const Money&); //перегрузка операции сравнения
	bool operator<(const Money& m) const;
	Money operator/(int divisor) const {
		long total_cop = this->rub * 100 + this->cop;
		total_cop /= divisor;
		long new_rub = total_cop / 100;
		int new_cop = total_cop % 100;
		return Money(new_rub, new_cop);
	}
	Money& operator+=(Money& other) {
		rub += other.rub;
		cop += other.cop;
		if (cop >= 100) {
			rub += cop / 100;
			cop %= 100;
		}
		return *this;
	}
	//глобальные функции ввода-вывода
	friend istream& operator>>(istream& in, Money& m);
	friend ostream& operator<<(ostream& out, const Money& m);
};

