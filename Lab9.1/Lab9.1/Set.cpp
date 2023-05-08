#include "Set.h"
#include "iostream"

Set::Set(int s, int k)
{
	size = s;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = k;
	beg.elem = &data[0];
	end.elem = &data[size];
}
//конструктор копирования
Set::Set(const Set& a)
{
	size = a.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	beg = a.beg;
	end = a.end;
}
//деструктор
Set::~Set() { delete[]data; data = 0; }
//операция присваивания
Set& Set::operator=(const Set& a)
{
	if (this == &a)return *this;
	size = a.size;
	if (data != 0) delete[]data;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	return *this;
	beg = a.beg;
	end = a.end;
	return *this;
}
//операция доступа по индексу
int& Set::operator[](int index)
{
	if (index > size) throw 1;
	else return data[index];
}
//операция для получения длины вектора
int Set::operator ()() { return size; }
//проверка принадлежности числа множеству
bool Set::operator<(int value) const
{
	for (int i = 0; i < size; ++i) {
		if (data[i] == NULL) { throw 3; }
		else
		{
			if (data[i] >= value)
			{
				return data[i] == value;
			}
		}
	}
	return false;
}
// проверка на неравенство
bool Set::operator!=(const Set& a) {
	if (!this || !&a) {
		throw 2;
	}
	return data != a.data;
}
int Set:: operator+(int n) const
{
	if (n > size) throw 1;
	else return data[n];
} //переход вправо к элементу с номером n 
//операции для ввода-выода
ostream& operator<<(ostream& out, const Set& a)
{
	for (int i = 0; i < a.size; ++i)
		out << a.data[i] << " ";
	return out;
}
istream& operator>>(istream& in, Set& a)
{
	for (int i = 0; i < a.size; ++i)
		in >> a.data[i];
	return in;
}