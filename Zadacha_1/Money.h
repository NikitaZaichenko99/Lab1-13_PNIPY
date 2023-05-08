#pragma once
#include <iostream>

using namespace std;

class Money
{
	long rub; int cop;

public:
	Money() { rub = 0; cop = 0; }; //����������� ��� ����������
	Money(long r, int c) { rub = r; cop = c; } //����������� � �����������
	Money(const Money& m) { rub = m.rub; cop = m.cop; } //����������� �����������
	~Money() {}; //����������
	int get_rub() { return rub; } //��������
	int get_cop() { return cop; } //��������
	void set_rub(long r) { rub = r; } //�����������
	void set_cop(int c) { cop = c; } //�����������
	Money& operator=(const Money& m);
	//������������� ��������
	Money& operator++(); //���������� ���������� �������� ���������
	Money operator++(int); //����������� ��������
	Money operator+(const Money&); //���������� �������� �������� ��������
	Money operator-(const Money&); //���������� �������� �������� ���������
	bool operator==(const Money&); //���������� �������� ���������
	bool operator!=(const Money&); //���������� �������� ���������
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
	//���������� ������� �����-������
	friend istream& operator>>(istream& in, Money& m);
	friend ostream& operator<<(ostream& out, const Money& m);
};

