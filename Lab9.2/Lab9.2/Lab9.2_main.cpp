#include "Set.h"
#include "error.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, k, l, j, s;
	//�������������� ����
	try
	{
		Set a(5);
		cout << "��������� a: " << endl;
		cout << a << endl;
		cin >> a;
		cout << "������� ������� ������ ������ ��������: " << endl;
		cin >> n;
		cout << "������� ����� ��������: " << endl;
		cin >> k;
		a[n - 1] = k;
		cout << "��������� a: " << endl;
		cout << a << endl;
		cout << endl << "��������� ��������� ������� � ������� �������� ��������� a: " << endl;
		cout << "������� ������ �������� ��� ���������: " << endl;
		cin >> l; cin >> j;
		cout << endl << a[l - 1] << " != " << a[j - 1] << endl;
		if (a[l - 1] != a[j - 1]) { cout << "�������� �� �����" << endl; }
		else { cout << "�������� �����" << endl; }
		cout << endl << "������� ������� ��� �������� �������������� ���������: ";
		cin >> s;
		if (a < s) { cout << "�������� ����������� ��������� a" << endl; }
		else { cout << "�������� �� ����������� ��������� a" << endl; }
		cout << "������� ������ � �������� � ������� n, ������� n: " << endl;
		cin >> j; j = j - 1;
		cout << "������� � ������� n: " << a + j;
	}
	//���������� ����������
	catch (Error& e)
	{
		e.what();
	}
	return 0;
}