#include "Book.h"
#include "List.h"
#include "Object.h"
#include "Print.h"
#include "Dialog.h"
#include "Event.h"
#include <windows.h>
#include <iostream>


using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "������� �������\n��������� �������: " << endl;
	cout << "m ������� ������\n+ �������� ������ � ������\n- ������� ������ �� ������\n";
	cout << "s �������� ������\nz �������� ����� ������ �� �������\nq ����� ������\n";
	Dialog D;
	D.Execute();
}