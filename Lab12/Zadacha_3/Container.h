#pragma once
#include <iostream>
using namespace std;
template <class T> //T - �������� �������
class Vector
{
public:
	//����������� � �����������: �������� ������ ��� s ��������� � ��������� �� 
	//��������� k
	Vector(int s, T k);
	//����������� � �����������
	Vector(const Vector<T>& a);
	//����������
	~Vector();
	//�������� ������������
	Vector& operator=(const Vector<T>& a);
	//�������� ������� �� �������
	T& operator[](int index);
	//�������� ��� ���������� ���������
	Vector operator+(const T k);
	//�������� ��� ���������� ������������� �������� � ���������� � �����
	Vector& addMaxToEnd();
	//�������� �������� �� �����
	void removeByKey(const T k);
	//�������� ���������� �������� �������� � ������� ��������
	void addToEach();
	//��������, ������������ ����� �������
	int operator()();
	//������������� �������� �����-������
	// <> - ��������� �� ��, ��� ������� �������� ��������
	friend ostream& operator<< <>(ostream& out, const Vector<T>& a);
	friend istream& operator>> <>(istream& in, Vector<T>& a);
private:
	int size;//������ �������
	T* data;//�������� �� ������������ ������ �������� �������
};
//����������� � �����������
template <class T>
Vector<T>::Vector(int s, T k)
{
	size = s;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = k;
}
//����������� �����������
template <class T>
Vector<T>::Vector(const Vector& a)
{
	size = a.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
}
//����������
template <class T>
Vector<T>::~Vector()
{
	delete[]data;
	data = 0;
}
//�������� ������������
template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& a)
{
	if (this == &a)return *this;
	size = a.size;
	if (data != 0) delete[]data;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	return *this;
}
//�������� ������� �� �������
template <class T>
T& Vector<T>::operator[](int index)
{
	if (index < size) return data[index];
	else cout << "\nError! Index>size";
}
//�������� ��� ���������� ���������
template <class T>
Vector<T> Vector<T>::operator+(const T k)//+k
{
	Vector<T> temp(size, k);//�������������� ��������� ������ ����� ���������
	for (int i = 0; i < size; ++i)
		temp.data[i] = data[i] + k;
	return temp;
}
//�������� ��� ���������� ������������� �������� � ���������� � �����
template<class T>
Vector<T>& Vector<T>::addMaxToEnd()
{
	auto maxVal = max_element(data, data + size);
	T maxValue = *maxVal;
	size++;
	T* temp = new T[size];
	for (int i = 0; i < size - 1; i++)
		temp[i] = data[i];
	temp[size - 1] = maxValue;
	delete[]data;
	data = temp;
	cout << "������������ ������� = " << maxValue << endl;
	return *this;
}
//�������� �������� �� �����
template <class T>
void Vector<T>::removeByKey(const T k)
{
	for (int i = 0; i < size; i++)
	{
		if (data[i] == k)
		{
			for (int j = i; j < size - 1; j++)
			{
				data[j] = data[j + 1];
			}
			size--;
			break;
		}
	}
}
//�������� ���������� �������� �������� � ������� ��������
template <class T>
void Vector<T>::addToEach()
{
	T sum;
	for (int i = 0; i < size; i++)
	{
		sum += data[i];
	}
	T average = sum / size;
	cout << "������� �������� = " << average << endl;
	for (int i = 0; i < size; i++)
	{
		data[i] += average;
	}
}

//�������� ��� ��������� ����� �������
template <class T>
int Vector<T>::operator ()()
{
	return size;
}
//�������� ��� �����-������
template <class T>
ostream& operator<< (ostream& out, const Vector<T>& a)
{
	for (int i = 0; i < a.size; ++i)
		out << a.data[i] << " ";
	return out;
}
template <class T>
istream& operator>> (istream& in, Vector<T>& a)
{
	for (int i = 0; i < a.size; ++i)
		in >> a.data[i];
	return in;
}