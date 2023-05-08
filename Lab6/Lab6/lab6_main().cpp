#include "Set.h"
#include "iostream"

void main()
{
	setlocale(LC_ALL, "Russian");
	int n, k, l, j, s;
	Set a(5);
	cout << "ћножнство a: " << endl;
	cout << a << endl;
	cin >> a;
	cout << "ћножнство a: " << endl;
	cout << a << endl;
	cout << "¬ведите элемент котрый хотите заменить: " << endl;
	cin >> n;
	cout << "¬ведите новое значение: " << endl;
	cin >> k;
	a[n - 1] = k;
	cout << "ћножнство a: " << endl;
	cout << a << endl;
	Set b(10);
	cout << "ћножество b из 10 элементов: " << endl;
	cout << b << endl;
	b = a;
	cout << "ѕрисвоили множеству b значени€ вектора a: " << endl;
	cout << b << endl;
	Set c(10); 
	c = b + 100;
	cout << "Cоздали множество c из 10 элементов и увеличили на 100: " << endl;
	cout << c << endl;
	cout << endl << "ƒлина множества a = " << a() << endl;
	cout << endl << "ѕровер€ем неравенство первого и второго элемента множества a: ";
	cout << endl << a[0] << " != " << a[1] << endl;
	if (a[0] != a[1]) { cout << "Ёлементы не равны" << endl; } 
	else { cout << "Ёлементы равны" << endl; }
	cout << endl << "¬ведите элимент дл€ проверки принодлежности множеству: ";
	cin >> l;
	if (a < l) { cout << "Ёлементы принадлежит множеству a" << endl; }
	else { cout << "Ёлементы не принадлежит множеству a" << endl; }
	cout << "¬озвращаем первый элемент множеству a" << endl;
	cout << "ѕервый элемент: " << *(a.first()) << endl;
	Iterator i = a.first();
	cout << "ѕереход вправо к элементу с номером n, введите n: " << endl;
	cin >> j;
	j = j - 1;
	Iterator d;
	d = i+j;
	cout << "Ёлемент с номером n: " << *d;
}