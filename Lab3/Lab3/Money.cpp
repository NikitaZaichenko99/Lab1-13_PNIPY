#include "Money.h"
#include <iostream>

using namespace std;

//���������� �������� ������������
Money& Money::operator=(const Money& m)
{
	//�������� �� ����������������
	if (&m == this) return *this;
	rub = m.rub;
	cop = m.cop;
	return *this;
}
//���������� ���������� �������� ���������
Money& Money::operator++()
{
	long e = rub + (cop / 100);
	rub = e;
	cop = cop % 100;
	return *this;
}
//���������� ����������� �������� ���������
Money Money::operator ++(int)
{
	long e = rub + (cop / 100);
	Money t(rub, cop);
	rub = e;
	cop = cop % 100;
	return t;
}
//���������� �������� �������� ��������
Money Money::operator+(const Money& m)
{
	long rubs = rub + m.rub;
	int cops = cop + m.cop;

	if (cops >= 100) {   // ��������� ������, ����� cop >= 100
		rubs += 1;
		cops -= 100;
	}
	Money p(rubs,cops);
	return p;
}
//���������� �������� �������� ���������
Money Money::operator-(const Money& m)
{
	double total = rub + cop / 100.0 - (m.rub + m.cop / 100.0);
	long rub = static_cast<long>(total); // static_cast: �������� �������������� ����� ������
	int cop = static_cast<int>((total - rub) * 100);

	if (cop < 0) {   // ��������� ������, ����� cop < 0
		rub -= 1;
		cop += 100;
	}

	if (rub < 0) {   // ��������� ������, ����� rub < 0
		rub = 0;
		cop = 0;
	}
	Money p(rub, cop);
	return p;
}
//���������� �������� ��������� ==
bool Money::operator==(const Money& m)
{
	if (rub == m.rub && cop == m.cop){ return true; }
	else { return false; }
}
//���������� �������� ��������� !=
bool Money::operator!=(const Money& m)
{
	if (rub != m.rub || cop != m.cop) { return true; }
	else { return false; }
}
//���������� ���������� �������-�������� �����
istream& operator>>(istream& in, Money& m)
{
	cout << "������� ����� = "; in >> m.rub;
	cout << "������� ������� = "; in >> m.cop;
	cout << endl;
	return in;
}
//���������� ���������� �������-�������� ������
ostream& operator<<(ostream& out, const Money& m)
{
	return (out << m.rub << "," << m.cop);
}
