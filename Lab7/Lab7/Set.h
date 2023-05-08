#pragma once
#include <iostream>

using namespace std;

template <class T> //T - параметр шаблона
class Set
{
public:
	Set(int s = 0); //конструктор с параметрами
	Set(const Set<T>& a); //конструктор копирования
	~Set(); //деструктор
	Set& operator=(const Set<T>& a); //оператор присваивания
	T& operator[](int index); //операция доступа по индексу
	int operator()(); //операция, возвращающая длину множества
	bool operator<(const T& a) const; //принадлежность числа множеству;
	//перегруженные операции ввода-вывода <> - указывают на то, что функция является шаблоном
	friend ostream& operator<< <>(ostream& out, const Set<T>& a);
	friend istream& operator>> <>(istream& in, Set<T>& a);
private:
	int size; //размер множества
	T* data; //укзатель на динамический массив значений множества
};

//конструктор с параметрами
template<class T>
Set<T>::Set(int n) {
	size = n;
	data = new T[size];
}
//конструктор копирования
template <class T>
Set<T>::Set(const Set& a)
{
	size = a.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
}
//деструктор
template <class T>
Set<T>::~Set()
{
	delete[]data;
	data = 0;
}
//операция присваивания
template<class T>
Set<T>& Set<T>::operator=(const Set<T>& a) {
	if (this != &a) { // проверка на самоприсваивание
		delete[] data;
		size = a.size;
		data = new T[size];
		for (int i = 0; i < size; i++)
			data[i] = a.data[i];
	}
	return *this;
}
//операция доступа по индексу
template <class T>
T& Set<T>::operator[](int index)
{
	if (index < size) return data[index];
	else cout << "\nError! Index>size";
}
//операция для получения длины множества
template <class T>
int Set<T>::operator ()() { return size; }
//принадлежность числа множеству;
template<class T>
bool Set<T>::operator<(const T& a) const {
	for (int i = 0; i < size; i++) {
		if (data[i] == a) {
			return true;
		}
	}
	return false;
}
//операции для ввода-вывода
template <class T>
ostream& operator<< (ostream& out, const Set<T>& a)
{
	for (int i = 0; i < a.size; ++i)
		out << a.data[i] << " " << endl;
	return out;
}
template <class T>
istream& operator>> (istream& in, Set<T>& a)
{
	for (int i = 0; i < a.size; ++i)
		in >> a.data[i];
	return in;
}
//template<class T>
//Set<T> Set<T>::operator*(const Set<T>& a) const {
//	Set<T> c(size);
//	int k = 0;
//	for (int i = 0; i < size; i++)
//		if (find(a.data, a.data + a.size, data[i]) != a.data + a.size) {
//			c.data[k] = data[i];
//			k++;
//		}
//	c.size = k;
//	return c;
//}
