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
	int operator()(); //��������, ������������ ����� ����������
	bool operator<(int value) const; //�������� �������������� ����� ���������
	bool operator!=(const Set&); // �������� �� �����������
	int operator+(int n) const; //������� ������ � �������� � ������� n 
	friend ostream& operator<<(ostream& out, const Set& a); //������������� �������� ������
	friend istream& operator>>(istream& in, Set& a); //������������� �������� �����
	Iterator first() { return beg; } //���������� ��������� �� ������ �������
	Iterator last() { return end; } //���������� ��������� �� ������� ��������� �� ���������
private:
	int size; //������ ���������
	int* data; //�������� �� ������������ ������ �������� �������
	Iterator beg; //��������� �� ������ ������� ���������
	Iterator end; //��������� �� ������� ��������� �� ���������
};