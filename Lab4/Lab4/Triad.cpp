#include "Triad.h"

//конструктор без параметров
Triad::Triad(void) { first = 0; second = 0; third = 0; }
//конструктор с параметрами
Triad::Triad(int M, int C, int P) { first = M; second = C; third = P; }
//конструктор копировани€
Triad::Triad(const Triad& Triad) { first = Triad.first; second = Triad.second; third = Triad.third; }
//деструктор
Triad::~Triad(void) {}
//модификаторы
void Triad::Set_first(int M) { first = M; }
void Triad::Set_second(int C){ second = C; }
void Triad::Set_third(int P){ third = P; }
//перегрузка префиксной операции инкремент
Triad& Triad::operator++()
{
	while(third > 60) { second += 1; third -= 60; }
	while (second > 60) { first += 1; second -= 60; }
	return *this;
}
//перегрузка операции присваивани€
Triad& Triad::operator=(const Triad& c)
{
	if (&c == this) return *this;
	first = c.first; second = c.second; third = c.third;
	return *this;
}
//перегрузка операции сравнени€ ==
bool Triad::operator==(const Triad& l) { return (first == l.first && second == l.second && third == l.third); }
//перегрузка операции сравнени€ !=
bool Triad::operator!=(const Triad& l) { return !(*this == l); }
//глобальна€ функци€ дл€ ввода
istream& operator>>(istream& in, Triad& c)
{
	cout << "\nfirst: "; in >> c.first;
	cout << "second: "; in >> c.second;
	cout << "third: "; in >> c.third;
	return in;
}
//глобальна€ функци€ дл€ вывода
ostream& operator<<(ostream& out, const Triad& c)
{
	out << "\nTriad: " << c.first << " : " << c.second << " : " << c.third;
	return out;
}