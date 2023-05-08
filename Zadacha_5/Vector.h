#pragma once
#include <iostream>
#include <stack>
#include <vector>
#include <C:\Users\nikit\source\repos\zadacha_2/Money.h>

template<class T>
class Vector
{
	stack <T> s;//���������
	int len;//������ ����������
public:
	Vector();//����������� ��� ����������
	Vector(int n);//����������� � �����������
	Vector(const Vector<T>&);//����������� �����������
	void Print();
	T Srednee();
	void Add(T el);
	T Max();
	T removeByKey(T el);
	void Add_srednee(T el);
};
//����������� ����� � ������
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
//����������� ������� � ����
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
//����������� ��� ����������
template <class T>
Vector<T>::Vector() { len = 0; }
//����������� � ����������
template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.push(a);//�������� � ���� ������� �
	}
	len = s.size();
}
//����������� �����������
template <class T>
Vector<T>::Vector(const Vector<T>& v)
{
	len = v.len;
	// �������� �������� ����� v.s � ������ v
	std::vector<T> vec = copy_stack_to_vector(v.s);
	// �������� ������ v � ���� s
	s = copy_vector_to_stack(vec);
}
//������
template <class T>
void Vector<T>::Print()
{
	//�������� ���� � ������
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())//���� ���� �� ������
	{
		cout << s.top() << endl;//����� �������� � ������� �����
		s.pop();//������� ������� �� �������
	}
	//�������� ������ � ����
	s = copy_vector_to_stack(v);
}
//���������� �������� ��������
template <class T>
T Vector<T>::Srednee()
{
	//�������� ���� � ������
	vector<T> v = copy_stack_to_vector(s);
	int n = 1;//���������� ��������� � �����
	T sum = s.top();//��������� �������� ��� �����
	s.pop();//������� ������� �� ������� �����
	while (!s.empty())//���� ���� �� ������
	{
		sum = sum + s.top();//��������� � ����� ������� �� ������� �����
		s.pop();//������� ������� �� ������� �����
		n++;//����������� ���������� ���������
	}
	//�������� ������ � ����
	s = copy_vector_to_stack(v);
	return sum / n;
}
//���������� �������� el � ���� � �����
template <class T>
void Vector<T>::Add(T el) { s.push(el); }
//����� ������������� ��������
template <class T>
T Vector<T>::Max()
{
	T m = s.top();//m ��������� �������� �� ������� �����
	//� ������ ����������� �������� �����
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())//���� ���� �� ������
	{
		//���������� m � ������� � ������� �����
		if (s.top() > m)m = s.top();
		s.pop();//������� ������� �� ������� �����
	}
	s = copy_vector_to_stack(v);//�������� ������ � ����
	return m;
}
//���������� �������� � �������� ������ � �������� ��� �� ����������
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
//���������� �������� ��������������� ��������� ����������
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