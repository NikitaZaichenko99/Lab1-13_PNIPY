#include "Money.h"
#include <iostream>

using namespace std;

//перегрузка операции присваивания
Money& Money::operator=(const Money& m)
{
	//проверка на самоприсваивание
	if (&m == this) return *this;
	rub = m.rub;
	cop = m.cop;
	return *this;
}
//перегрузка префиксной операции инкремент
Money& Money::operator++()
{
	long e = rub + (cop / 100);
	rub = e;
	cop = cop % 100;
	return *this;
}
//перегрузка постфиксной операции инкремент
Money Money::operator ++(int)
{
	long e = rub + (cop / 100);
	Money t(rub, cop);
	rub = e;
	cop = cop % 100;
	return t;
}
//перегрузка бинарной операции сложения
Money Money::operator+(const Money& m)
{
	long rubs = rub + m.rub;
	int cops = cop + m.cop;

	if (cops >= 100) {   // обработка случая, когда cop >= 100
		rubs += 1;
		cops -= 100;
	}
	Money p(rubs,cops);
	return p;
}
//перегрузка бинарной операции вычитания
Money Money::operator-(const Money& m)
{
	double total = rub + cop / 100.0 - (m.rub + m.cop / 100.0);
	long rub = static_cast<long>(total); // static_cast: оператор преобразования типов данных
	int cop = static_cast<int>((total - rub) * 100);

	if (cop < 0) {   // обработка случая, когда cop < 0
		rub -= 1;
		cop += 100;
	}

	if (rub < 0) {   // обработка случая, когда rub < 0
		rub = 0;
		cop = 0;
	}
	Money p(rub, cop);
	return p;
}
//перегрузка операции сравнения ==
bool Money::operator==(const Money& m)
{
	if (rub == m.rub && cop == m.cop){ return true; }
	else { return false; }
}
//перегрузка операции сравнения !=
bool Money::operator!=(const Money& m)
{
	if (rub != m.rub || cop != m.cop) { return true; }
	else { return false; }
}
//перегрузка глобальной функции-операции ввода
istream& operator>>(istream& in, Money& m)
{
	cout << "Введите рубли = "; in >> m.rub;
	cout << "Введите копейки = "; in >> m.cop;
	cout << endl;
	return in;
}
//перегрузка глобальной функции-операции вывода
ostream& operator<<(ostream& out, const Money& m)
{
	return (out << m.rub << "," << m.cop);
}
