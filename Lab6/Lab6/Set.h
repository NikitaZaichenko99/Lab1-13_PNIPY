#pragma once
#include "iostream"

using namespace std;

class Iterator
{
	friend class Set;//������������� �����
public:
	Iterator() { elem = 0; }//����������� ��� ����������
	Iterator(const Iterator& it) { elem = it.elem; }//����������� �����������
	int& operator *() const { return*elem; } //������������� �������� �������������
	Iterator operator+(int n) const { auto copy = *this; advance(copy.elem, n); return copy; } //������� ������ � �������� � ������� n 
private:
	int* elem; //��������� �� ������� ���� int
};

class Set
{
public:
	Set(int s, int k = 0); //����������� � �����������: �������� ������ ��� s ��������� � ��������� �� ��������� k
	Set(const Set& a); //����������� � �����������
	~Set(); //����������
	Set& operator=(const Set& a); //�������� ������������
	int& operator[](int index); //�������� ������� �� �������
	Set operator+(const int k); //�������� ��� ���������� ���������
	int operator()(); //��������, ������������ ����� ���������
	bool operator<(int value) const; //�������� �������������� ����� ���������
	bool operator!=(const Set& ); // �������� �� �����������
	friend ostream& operator<<(ostream& out, const Set& a); //������������� �������� ������
	friend istream& operator>>(istream& in, Set& a); //������������� �������� �����
	Iterator first() { return beg; } //���������� ��������� �� ������ �������
	Iterator last() { return end; } //���������� ��������� �� ������� ��������� �� ���������
private:
	int size; //������ ���������
	int* data; //�������� �� ������������ ������ �������� ���������
	Iterator beg; //��������� �� ������ ������� ���������
	Iterator end; //��������� �� ������� ��������� �� ���������
};
