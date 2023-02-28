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
	fraction t;//создали временные переменные
	fraction s;
	t.Init(F, S);//инициализировали пол€ переменной t и s с помощью параметров функции
	s.Init(3.0, 2.1);
	t.Show();
	s.Show();
	double a = t.Distation(t, s);
	return a;//вернули значение переменной t
}void main()
{
	//определение переменных ј и ¬
	fraction A;
	fraction B;
	fraction C;
	A.Init(3.0, 2.1);//инициализаци€ переменной ј
	B.Read();//ввод полей переменных ¬
	A.Show();//вывод значений полей переменной ј
	B.Show();//вывод значений полей переменной ¬
	//вычисление рассто€ни€
	cout << endl << "Distation = " << C.Distation(A, B) << endl;
	//указатели
	fraction* XY = new fraction;//выделение пам€ти под динамическую переменную
	fraction* FS = new fraction;
	fraction* D = new fraction;
	XY->Init(2.0, 5.1);//инициализаци€
	FS->Read();
	XY->Show();//вывод значений полей
	FS->Show();
	cout << endl << "Distation = " << D->Distation(*XY, *FS) << endl;
	//массивы
	fraction mas[4];//определение массива
	for (int i = 0; i < 4; i++)
		mas[i].Read();//чтение значений полей
	for (int i = 0; i < 4; i++)
		mas[i].Show(); //вывод значений полей
	for (int i = 0; i < 4;)
	{
		cout << endl << "Distation " << i + 1 << " and " << i + 2 << " = ";
		cout << mas[i].Distation(mas[i], mas[i + 1]) << endl; //вычисление расто€ни€
		i = i + 2;
	}
	//динамические масивы
	fraction* p_mas = new fraction[4];//выделение пам€ти
	for (int i = 0; i < 4; i++)
		p_mas[i].Read();//чтение значений полей
	for (int i = 0; i < 4; i++)
		p_mas[i].Show();//вывод значений полей
	for (int i = 0; i < 4;)
	{
		cout << endl << "Distation " << i + 1 << " and " << i + 2 << " = ";
		cout << p_mas[i].Distation(p_mas[i], p_mas[i + 1]) << endl; //вычисление расто€ни€
		i = i + 2;
	}
	//вызов функции make_double()
	double x; double y;
	cout << endl << "first? "; cin >> x;
	cout << "second? "; cin >> y;
	//переменна€ F формируетс€ с помощью функции make_double()
	double F = make_double(x, y);
	cout << endl << "Distation " << F << endl;

	return;
}