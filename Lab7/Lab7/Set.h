#pragma once
#include <iostream>

using namespace std;

template <class T> //T - �������� �������
class Set
{
public:
	Set(int s = 0); //����������� � �����������
	Set(const Set<T>& a); //����������� �����������
	~Set(); //����������
	Set& operator=(const Set<T>& a); //�������� ������������
	T& operator[](int index); //�������� ������� �� �������
	int operator()(); //��������, ������������ ����� ���������
	bool operator<(const T& a) const; //�������������� ����� ���������;
	//������������� �������� �����-������ <> - ��������� �� ��, ��� ������� �������� ��������
	friend ostream& operator<< <>(ostream& out, const Set<T>& a);
	friend istream& operator>> <>(istream& in, Set<T>& a);
private:
	int size; //������ ���������
	T* data; //�������� �� ������������ ������ �������� ���������
};

//����������� � �����������
template<class T>
Set<T>::Set(int n) {
	size = n;
	data = new T[size];
}
//����������� �����������
template <class T>
Set<T>::Set(const Set& a)
{
	size = a.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
}
//����������
template <class T>
Set<T>::~Set()
{
	delete[]data;
	data = 0;
}
//�������� ������������
template<class T>
Set<T>& Set<T>::operator=(const Set<T>& a) {
	if (this != &a) { // �������� �� ����������������
		delete[] data;
		size = a.size;
		data = new T[size];
		for (int i = 0; i < size; i++)
			data[i] = a.data[i];
	}
	return *this;
}
//�������� ������� �� �������
template <class T>
T& Set<T>::operator[](int index)
{
	if (index < size) return data[index];
	else cout << "\nError! Index>size";
}
//�������� ��� ��������� ����� ���������
template <class T>
int Set<T>::operator ()() { return size; }
//�������������� ����� ���������;
template<class T>
bool Set<T>::operator<(const T& a) const {
	for (int i = 0; i < size; i++) {
		if (data[i] == a) {
			return true;
		}
	}
	return false;
}
//�������� ��� �����-������
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
