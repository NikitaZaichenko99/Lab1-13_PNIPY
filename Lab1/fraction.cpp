#include <iostream>
#include "fraction.h"

using namespace std;
//реализация метода для инициализации полей структуры
void fraction::Init(double F, double S)
{
	first = F; second = S;
}
//реализация метода для чтения значений полей структуры
void fraction::Read()
{
	cout << endl << "first? "; cin >> first;
	cout << "second? "; cin >> second;
}
//реализация метода для вывода значений полей структуры
void fraction::Show()
{
	cout << endl << "first = " << first;
	cout << endl << "second = " << second;
	cout << endl;
}
//метод вычисления расстояния
double fraction::Distation(fraction A, fraction B)
{
	return (pow((B.first - A.first), 2)) + (pow((B.second - A.second),2));
}

