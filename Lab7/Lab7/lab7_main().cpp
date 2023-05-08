#include "Set.h"
#include "Money.h"
#include <iostream>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	Set<Money> A(5); // создаем множество размером 5
	cout << "Введите " << A() << " элементов класса Money:\n"; 
	cin >> A;
	cout << "A: " << endl << A << endl;
	Set<Money> B(3); // создаем множество размером 3
	cout << "Введите " << B() << " элементов класса Money:\n";
	cin >> B;
	cout << "B: " << endl << B << endl;
	Money x(100, 50);
	if (A<x) // < число – принадлежность числа множеству
		cout << x << " Принадлежит A" << endl;
	else
		cout << x << " Не принадлежит A" << endl;
	if (x != B[0]) //[] – доступа по индексу и != - проверка на неравенство
		cout << x << " Не равен первому элементу B" << endl;
	else
		cout << x << " Равен первому элементу B" << endl;
	return;
}