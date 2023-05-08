#include "Money.h"
#include <iostream>

using namespace std;

//перегрузка операции присваивани€
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
//перегрузка бинарной операции сложени€
Money Money::operator+(const Money& m)
{
	long rubs = rub + m.rub;
	int cops = cop + m.cop;

	if (cops >= 100) {   // обработка случа€, когда cop >= 100
		rubs += 1;
		cops -= 100;
	}
	Money p(rubs, cops);
	return p;
}
//перегрузка бинарной операции вычитани€
Money Money::operator-(const Money& m)
{
	double total = rub + cop / 100.0 - (m.rub + m.cop / 100.0);
	long rub = static_cast<long>(total); // static_cast: оператор преобразовани€ типов данных
	int cop = static_cast<int>((total - rub) * 100);

	if (cop < 0) {   // обработка случа€, когда cop < 0
		rub -= 1;
		cop += 100;
	}

	if (rub < 0) {   // обработка случа€, когда rub < 0
		rub = 0;
		cop = 0;
	}
	Money p(rub, cop);
	return p;
}
//перегрузка операции сравнени€ ==
bool Money::operator==(const Money& m)
{
	if (rub == m.rub && cop == m.cop) { return true; }
	else { return false; }
}
//перегрузка операции сравнени€ !=
bool Money::operator!=(const Money& m)
{
	if (rub != m.rub || cop != m.cop) { return true; }
	else { return false; }
}
//перегрузка глобальной функции-операции ввода
istream& operator>>(istream& in, Money& m)
{
	cout << "¬ведите рубли = "; in >> m.rub;
	cout << "¬ведите копейки = "; in >> m.cop;
	cout << endl;
	return in;
}
//перегрузка глобальной функции-операции вывода
ostream& operator<<(ostream& out, const Money& m)
{
	return (out << m.rub << "," << m.cop);
}
//дружественные функции дл€ работы с файловыми потоками
fstream& operator>>(fstream& fin, Money& m)
{
	fin >> m.rub;
	fin >> m.cop;
	return fin;
}
fstream& operator<<(fstream& fout, const Money& m)
{
	fout << m.rub << "\n" << m.cop << "\n";
	return fout;
}
