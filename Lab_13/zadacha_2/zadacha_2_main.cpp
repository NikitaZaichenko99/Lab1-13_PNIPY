#include "Vector.h"
#include <vector>
#include "Money.h"
#include <iostream>

using namespace std;

void main()
{
	int p, s;
	setlocale(LC_ALL, "rus");
	Vector<Money>vec(5);//������� ������ �� 5 ���������
	vec.Print();//������ �������
	p = vec.Max();//����� ������������ �������
	cout << "������������ ������� = " << vec[p] << endl;
	vec.Add(vec[p]); //���������� ��������
	vec.Print(); //������ �������
	cout << "������� ���� = "; cin >> s;
	cout << "��� ������� = " << vec[s] << endl;
	vec.Del(s);//��������
	vec.Print(); //������ �������
	Money m = vec.Srednee();//������� �������������
	cout << "������� �������� = " << m << endl;
	vec.Add_srednee();//�������� ������� ��������������
	vec.Print(); //������ �������

}