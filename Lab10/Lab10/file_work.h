#include "Money.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);//открыть для записи
	if (!stream) return -1;//ошибка открытия файла
	int n;
	Money m;
	cout << "Введите количество объектов\n"; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m; ++m;//ввод атрибутов объекта из стандартного потока 
		stream << m << "\n";//запись объекта в файловый поток
	}
	stream.close();//закрыть поток
	return n;//вернуть количество записанных объектов
}
int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);//открыть для чтения
	if (!stream)return -1;//ошибка открытия файла
	Money m; int i = 0;
	while (stream >> m)
	{
		cout << m << "\n";
		i++;
	}
	stream.close();
	return i;
}
int del_file(const char* f_name, int r, int c)
{
	fstream temp("temp", ios::out);//открыть для записи
	fstream stream(f_name, ios::in);//открыть для чтения
	if (!stream)return -1;//ошибка открытия файла
	int i = 0; Money m;
	while (stream >> m)//пока нет конца файла выполняем чтение объекта
	{
		//если прочитан признак конца файла,то выход из цикла
		if (stream.eof())break;
		i++;
		if (m.get_rub() != r && m.get_cop() != c)
			temp << m;
	}
	//закрыть файлы
	stream.close(); temp.close();
	remove(f_name);//удалить старый файл
	rename("temp", f_name);// переименовать temp
	return i;//количество прочитанных
}
int add_file(const char* f_name, int r, int c, Money pp)
{
	fstream temp("temp", ios::out);//открыть для записи
	fstream stream(f_name, ios::in);//открыть для чтения
	if (!stream) return -1;//ошибка открытия файла
	Money m; int i = 0, l = 0;
	while (stream >> m)
	{
		if (stream.eof()) break;
		i++;
		temp << m; //записать текущую запись в temp
		if (m.get_rub() == r && m.get_cop() == c)
		{
			temp << pp; //записать новую запись после текущей записи
			l++;
		}
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;//количество добавленных
}
int add_end(const char* f_name, Money pp)
{
	fstream stream(f_name, ios::app);//открыть для добавления
	if (!stream)return -1;//ошибка открытия файла
	stream << pp; //записать новую запись
	return 1;
}
int change_file(const char* f_name, int r, int c, Money pp)
{
	fstream temp("temp", ios::out);//открыть для записи
	fstream stream(f_name, ios::in);//открыть для чтения
	if (!stream)return -1;//ошибка открытия файла
	Money m; int i = 0, l = 0;
	/*char x;*/
	while (stream >> m)
	{
		if (stream.eof())break;
		i++;
		if (m.get_rub() == r && m.get_cop() == c)
		{
			m = m - pp;
			temp << m;
			if (m.get_rub() < 0) m.set_rub(0);
			if (m.get_cop() < 0) m.set_cop(0);
			l++;
		}
		else temp << m;
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;//количество измененных элементов
}