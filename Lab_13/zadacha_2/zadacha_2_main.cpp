#include "Vector.h"
#include <vector>
#include "Money.h"
#include <iostream>

using namespace std;

void main()
{
	int p, s;
	setlocale(LC_ALL, "rus");
	Vector<Money>vec(5);//создать вектор из 5 элементов
	vec.Print();//печать вектора
	p = vec.Max();//найти максимальный элемент
	cout << "Максимальный элемент = " << vec[p] << endl;
	vec.Add(vec[p]); //добавление элемента
	vec.Print(); //печать вектора
	cout << "Введите ключ = "; cin >> s;
	cout << "Ваш элемент = " << vec[s] << endl;
	vec.Del(s);//удаление
	vec.Print(); //печать вектора
	Money m = vec.Srednee();//среднее ариметическое
	cout << "Среднее значение = " << m << endl;
	vec.Add_srednee();//добавить среднее арифметическое
	vec.Print(); //печать вектора

}