#pragma once
#include <vector>
#include <iostream>
#include <C:\Users\nikit\source\repos\Zadacha_2\Money.h>


using namespace std;
//шаблон класса
template<class T>
class Vector
{
	vector <T> v;//последовательный контейнер для хранения элементов вектора
	int len;
public:
	Vector(void);//конструктор без параметра
	Vector(int n);
	T& operator[](int index);
	//конструктор с параметром
	void Print();//печать
	~Vector(void);//деструктор
	T Srednee();//вычисление среднего арифметического
	void Add(T el);//добавление элемента el в конец
	int Max();//найти номер максимальнго элемента
	void Del(int pos);//удалить элемент из позиции pos
	void Add_srednee();//добавить среднее арифметическое
};
//конструктор без параметра
template <class T>
Vector<T>::Vector()
{
	len = 0;
}
//деструктор
template <class T>
Vector<T>::~Vector(void)
{
}
//конструктор с параметром
template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	len = v.size();
}
//операция доступа по индексу
template <class T>
T& Vector<T>::operator[](int index)
{
	if (index < v.size()) return v[index];
	else cout << "\nError! Index>size";
}
//печать
template <class T>
void Vector<T>::Print()
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}
template<class T>
T Vector<T>::Srednee()
{
	T s = v[0];
	for (int i = 1; i < v.size(); i++)
		s = s + v[i];
	int n = v.size();
	return s / n;
}
//добавление элемента
template<class T>
void Vector<T>::Add(T el)
{
	v.insert(v.begin() + v.size(), el);
}
//поиск максимального элемента
template <class T>
int Vector<T>::Max()
{
	T m = v[0];
	int n = 0;
	for (int i = 1; i < v.size(); i++)
		if (v[i] > m)
		{
			m = v[i];
			n = i;
		}
	return n;
}
//удаление элемента из позиции pos
template<class T>
void Vector<T>::Del(int pos)
{
	v.erase(v.begin() + pos);
}
// Функция добавления к каждому элементу среднее арифметическое
template<class T>
void Vector<T>::Add_srednee()
{
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] + Srednee();
}