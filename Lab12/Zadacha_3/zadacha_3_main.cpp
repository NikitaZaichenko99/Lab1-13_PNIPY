#include <iostream>
#include "Container.h"
#include "Money.h"

using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");
	int n;
	Money m;
	cout << "N?"; cin >> n;
	Vector<Money> v(n, m);
	cin >> v;
	cout << "Контейнер: " << v << endl;
	v.addMaxToEnd();
	cout << "Добавили в конец максимальное значение: " << v << endl;
	Money k;
	cout << "Введите ключ " << endl; cin >> k;
	v.removeByKey(k);
	cout << "Удалили элемент " << v << endl;
	v.addToEach();
	cout << "Добавили среднее к каждому элементу " << v;
}
