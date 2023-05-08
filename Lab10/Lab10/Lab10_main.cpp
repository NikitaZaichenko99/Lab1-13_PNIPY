#include "Money.h"
#include "file_work.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Money m, m1;
	int k, c;
	char file_name[30];
	do
	{ //����
		cout << "\n1. �������� �����";
		cout << "\n2. ������ �����";
		cout << "\n3. ������� ������ �� �����";
		cout << "\n4. �������� ������ � ����";
		cout << "\n5. �������� ������ � �����";
		cout << "\n0. �����\n";
		cin >> c;
		switch (c)
		{
		case 1: cout << "������� �������� �����\n"; cin >> file_name;
			k = make_file(file_name);
			if (k < 0)cout << "�� ������� ������� ����\n";
			break;
		case 2: cout << "������� �������� �����\n"; cin >> file_name;
			k = print_file(file_name);
			if (k == 0)cout << "������ ����\n";
			if (k < 0)cout << "�� ������� ��������� ����\n";
			break;
		case 3: cout << "������� �������� �����\n"; cin >> file_name;
			long rub; int cop; cout << "������� �������� ������ � ������\n"; cin >> rub; cin >> cop;
			cout << rub << "," << cop << endl;
			k = del_file(file_name, rub, cop);
			if (k < 0)cout << "�� ������� ��������� ����\n";
			else cout << "������ �������\n";
			break;
		case 4: cout << "������� �������� �����\n";
			cin >> file_name;
			long rubs; int cops; cout << "������� �������� ������ � ������\n"; cin >> rubs; cin >> cops;
			cout << rubs << "," << cops << endl;
			cout << "������� ������� ��������� ���������\n";
			int s; cin >> s;
			for (int i = 0; i < s; i++)
			{
				cin >> m1;
				k = add_file(file_name, rubs, cops, m1);
				if (k < 0) cout << "�� ������� ��������� ����\n";
				if (k == 0) k = add_end(file_name, m1);
			}
			cout << "��������� " << s << " ���������\n";
			break;
		case 5: cout << "������� �������� �����\n";
			cin >> file_name;
			long rubss; int copss; cout << "������� �������� ������ � ������\n"; cin >> rubss; cin >> copss;
			cout << rubss << "," << copss << endl;
			Money m2(1,50);
			k = change_file(file_name, rubss, copss, m2);
			if (k < 0) cout << "�� ������� ��������� ����\n";
			if (k == 0) cout << "������ ����\n";
			break;
		}
	} while (c != 0);
}