#pragma once
#include <vector>
#include <iostream>
#include <C:\Users\nikit\source\repos\Zadacha_2\Money.h>


using namespace std;
//������ ������
template<class T>
class Vector
{
	vector <T> v;//���������������� ��������� ��� �������� ��������� �������
	int len;
public:
	Vector(void);//����������� ��� ���������
	Vector(int n);
	T& operator[](int index);
	//����������� � ����������
	void Print();//������
	~Vector(void);//����������
	T Srednee();//���������� �������� ���������������
	void Add(T el);//���������� �������� el � �����
	int Max();//����� ����� ������������ ��������
	void Del(int pos);//������� ������� �� ������� pos
	void Add_srednee();//�������� ������� ��������������
};
//����������� ��� ���������
template <class T>
Vector<T>::Vector()
{
	len = 0;
}
//����������
template <class T>
Vector<T>::~Vector(void)
{
}
//����������� � ����������
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
//�������� ������� �� �������
template <class T>
T& Vector<T>::operator[](int index)
{
	if (index < v.size()) return v[index];
	else cout << "\nError! Index>size";
}
//������
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
//���������� ��������
template<class T>
void Vector<T>::Add(T el)
{
	v.insert(v.begin() + v.size(), el);
}
//����� ������������� ��������
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
//�������� �������� �� ������� pos
template<class T>
void Vector<T>::Del(int pos)
{
	v.erase(v.begin() + pos);
}
// ������� ���������� � ������� �������� ������� ��������������
template<class T>
void Vector<T>::Add_srednee()
{
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] + Srednee();
}