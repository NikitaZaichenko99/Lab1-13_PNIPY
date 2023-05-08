#include "Set.h"
#include "error.h"
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
Set::Set(const Set& a)
{
	size = a.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	beg = a.beg;
	end = a.end;
}
Set::~Set() { delete[]data; data = 0; }
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
int& Set::operator[](int index)
{
	if (index > size) throw IndexError2();
	else if (index < 0) throw IndexError1();
	else return data[index];
}
int Set::operator ()() { return size; }
bool Set::operator<(int value) const
{
	for (int i = 0; i < size; ++i) {
		if (data[i] == NULL) { throw EmptySizeError(); }
		else if (i < 0) { throw IndexError1(); } 
		else if (i > size) {throw IndexError2(); }
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
bool Set::operator!=(const Set& a) {
	if (!this || !&a) {
		throw EmptySizeError();
	}
	return data != a.data;
}
int Set:: operator+(int n) const
{
	if (n > size || n < 0) throw IndexError();
	else return data[n];
}
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