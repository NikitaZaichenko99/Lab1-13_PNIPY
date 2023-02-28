#include <iostream>
#include "fraction.h"

using namespace std;

double make_double(double F, double S)
{
	if (F < 0 || S < 0)
	{
		cout << "Error" << endl;
		exit(1);
	}
	fraction t;//������� ��������� ����������
	fraction s;
	t.Init(F, S);//���������������� ���� ���������� t � s � ������� ���������� �������
	s.Init(3.0, 2.1);
	t.Show();
	s.Show();
	double a = t.Distation(t, s);
	return a;//������� �������� ���������� t
}void main()
{
	//����������� ���������� � � �
	fraction A;
	fraction B;
	fraction C;
	A.Init(3.0, 2.1);//������������� ���������� �
	B.Read();//���� ����� ���������� �
	A.Show();//����� �������� ����� ���������� �
	B.Show();//����� �������� ����� ���������� �
	//���������� ����������
	cout << endl << "Distation = " << C.Distation(A, B) << endl;
	//���������
	fraction* XY = new fraction;//��������� ������ ��� ������������ ����������
	fraction* FS = new fraction;
	fraction* D = new fraction;
	XY->Init(2.0, 5.1);//�������������
	FS->Read();
	XY->Show();//����� �������� �����
	FS->Show();
	cout << endl << "Distation = " << D->Distation(*XY, *FS) << endl;
	//�������
	fraction mas[4];//����������� �������
	for (int i = 0; i < 4; i++)
		mas[i].Read();//������ �������� �����
	for (int i = 0; i < 4; i++)
		mas[i].Show(); //����� �������� �����
	for (int i = 0; i < 4;)
	{
		cout << endl << "Distation " << i + 1 << " and " << i + 2 << " = ";
		cout << mas[i].Distation(mas[i], mas[i + 1]) << endl; //���������� ���������
		i = i + 2;
	}
	//������������ ������
	fraction* p_mas = new fraction[4];//��������� ������
	for (int i = 0; i < 4; i++)
		p_mas[i].Read();//������ �������� �����
	for (int i = 0; i < 4; i++)
		p_mas[i].Show();//����� �������� �����
	for (int i = 0; i < 4;)
	{
		cout << endl << "Distation " << i + 1 << " and " << i + 2 << " = ";
		cout << p_mas[i].Distation(p_mas[i], p_mas[i + 1]) << endl; //���������� ���������
		i = i + 2;
	}
	//����� ������� make_double()
	double x; double y;
	cout << endl << "first? "; cin >> x;
	cout << "second? "; cin >> y;
	//���������� F ����������� � ������� ������� make_double()
	double F = make_double(x, y);
	cout << endl << "Distation " << F << endl;

	return;
}