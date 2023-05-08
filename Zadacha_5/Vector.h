#pragma once
#include <iostream>
#include <stack>
#include <vector>
#include <C:\Users\nikit\source\repos\zadacha_2/Money.h>

template<class T>
class Vector
{
	stack <T> s;//контейнер
	int len;//размер контейнера
public:
	Vector();//конструктор без параметров
	Vector(int n);//конструктор с параметрами
	Vector(const Vector<T>&);//конструктор копирования
	void Print();
	T Srednee();
	void Add(T el);
	T Max();
	T removeByKey(T el);
	void Add_srednee(T el);
};
//копирование стека в вектор
template <class T>
vector<T> copy_stack_to_vector(stack<T> s)
{
	vector<T> v;
	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	return v;
}
//копирование вектора в стек
template <class T>
stack<T> copy_vector_to_stack(vector<T> v)
{
	stack<T> s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);
	}
	return s;
}
//конструктор без параметров
template <class T>
Vector<T>::Vector() { len = 0; }
//конструктор с параметром
template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.push(a);//добавить в стек элемент а
	}
	len = s.size();
}
//конструктор копирования
template <class T>
Vector<T>::Vector(const Vector<T>& v)
{
	len = v.len;
	// копируем значения стека v.s в вектор v
	std::vector<T> vec = copy_stack_to_vector(v.s);
	// копируем вектор v в стек s
	s = copy_vector_to_stack(vec);
}
//печать
template <class T>
void Vector<T>::Print()
{
	//копируем стек в вектор
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())//пока стек не пустой
	{
		cout << s.top() << endl;//вывод элемента в вершине стека
		s.pop();//удаляем элемент из вершины
	}
	//копируем вектор в стек
	s = copy_vector_to_stack(v);
}
//вычисление среднего значения
template <class T>
T Vector<T>::Srednee()
{
	//копируем стек в вектор
	vector<T> v = copy_stack_to_vector(s);
	int n = 1;//количество элементов в стеке
	T sum = s.top();//начальное значение для суммы
	s.pop();//удаляем элемент из вершины стека
	while (!s.empty())//пока стек не пустой
	{
		sum = sum + s.top();//добавляем в сумму элемент из вершины стека
		s.pop();//удаляем элемент из вершины стека
		n++;//увеличиваем количество элементов
	}
	//копируем вектор в стек
	s = copy_vector_to_stack(v);
	return sum / n;
}
//добавление элемента el в стек в конец
template <class T>
void Vector<T>::Add(T el) { s.push(el); }
//поиск максимального элемента
template <class T>
T Vector<T>::Max()
{
	T m = s.top();//m присвоить значение из вершины стека
	//в вектор скопировать элементы стека
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())//пока стек не пустой
	{
		//сравниваем m и элемент в вершине стека
		if (s.top() > m)m = s.top();
		s.pop();//удаляем элемент из вершины стека
	}
	s = copy_vector_to_stack(v);//копируем вектор в стек
	return m;
}
//Нахождение элемента с заданным ключом и удаление его из контейнера
template <class T>
T Vector<T>::removeByKey(T el)
{
	T m = el;
	vector<T> v;
	T t;
	while (!s.empty())
	{
		t = s.top();
		if (t != m)v.push_back(t);
		s.pop();
	}
	s = copy_vector_to_stack(v);
	return el;
}
//Добавление среднего арифметического элементов контейнера
template <class T>
void Vector<T>::Add_srednee(T el)
{
	T m = el;
	vector<T> v;
	T t;
	while (!s.empty())
	{
		t = s.top();
		v.push_back(t + m);
		s.pop();
	}
	s = copy_vector_to_stack(v);
}