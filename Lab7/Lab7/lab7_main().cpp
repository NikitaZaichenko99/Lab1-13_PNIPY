#include "Set.h"
#include "Money.h"
#include <iostream>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	Set<Money> A(5); // ������� ��������� �������� 5
	cout << "������� " << A() << " ��������� ������ Money:\n"; 
	cin >> A;
	cout << "A: " << endl << A << endl;
	Set<Money> B(3); // ������� ��������� �������� 3
	cout << "������� " << B() << " ��������� ������ Money:\n";
	cin >> B;
	cout << "B: " << endl << B << endl;
	Money x(100, 50);
	if (A<x) // < ����� � �������������� ����� ���������
		cout << x << " ����������� A" << endl;
	else
		cout << x << " �� ����������� A" << endl;
	if (x != B[0]) //[] � ������� �� ������� � != - �������� �� �����������
		cout << x << " �� ����� ������� �������� B" << endl;
	else
		cout << x << " ����� ������� �������� B" << endl;
	return;
}