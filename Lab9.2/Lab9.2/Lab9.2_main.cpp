#include "Set.h"
#include "error.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, k, l, j, s;
	//контролируемый блок
	try
	{
		Set a(5);
		cout << "ћножнство a: " << endl;
		cout << a << endl;
		cin >> a;
		cout << "¬ведите элемент котрый хотите заменить: " << endl;
		cin >> n;
		cout << "¬ведите новое значение: " << endl;
		cin >> k;
		a[n - 1] = k;
		cout << "ћножнство a: " << endl;
		cout << a << endl;
		cout << endl << "ѕровер€ем равенство первого и второго элемента множества a: " << endl;
		cout << "¬ведите номера элемнтов дл€ сравнени€: " << endl;
		cin >> l; cin >> j;
		cout << endl << a[l - 1] << " != " << a[j - 1] << endl;
		if (a[l - 1] != a[j - 1]) { cout << "Ёлементы не равны" << endl; }
		else { cout << "Ёлементы равны" << endl; }
		cout << endl << "¬ведите элимент дл€ проверки принодлежности множеству: ";
		cin >> s;
		if (a < s) { cout << "Ёлементы принадлежит множеству a" << endl; }
		else { cout << "Ёлементы не принадлежит множеству a" << endl; }
		cout << "ѕереход вправо к элементу с номером n, введите n: " << endl;
		cin >> j; j = j - 1;
		cout << "Ёлемент с номером n: " << a + j;
	}
	//обработчик исключени€
	catch (Error& e)
	{
		e.what();
	}
	return 0;
}