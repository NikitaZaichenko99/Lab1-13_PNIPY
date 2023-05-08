#include "Money.h"
#include "file_work.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Money m, m1;
	int k, c;
	char file_name[30];
	do
	{ //Меню
		cout << "\n1. Создание файла";
		cout << "\n2. Печать файла";
		cout << "\n3. Удалить запись из файла";
		cout << "\n4. Добавить запись в файл";
		cout << "\n5. Изменить запись в файле";
		cout << "\n0. Выход\n";
		cin >> c;
		switch (c)
		{
		case 1: cout << "Введите название файла\n"; cin >> file_name;
			k = make_file(file_name);
			if (k < 0)cout << "Не удается создать файл\n";
			break;
		case 2: cout << "Введите название файла\n"; cin >> file_name;
			k = print_file(file_name);
			if (k == 0)cout << "Пустой файл\n";
			if (k < 0)cout << "Не удается прочитать файл\n";
			break;
		case 3: cout << "Введите название файла\n"; cin >> file_name;
			long rub; int cop; cout << "Введите значение рублей и копеек\n"; cin >> rub; cin >> cop;
			cout << rub << "," << cop << endl;
			k = del_file(file_name, rub, cop);
			if (k < 0)cout << "Не удается прочитать файл\n";
			else cout << "Запись удалена\n";
			break;
		case 4: cout << "Введите название файла\n";
			cin >> file_name;
			long rubs; int cops; cout << "Введите значение рублей и копеек\n"; cin >> rubs; cin >> cops;
			cout << rubs << "," << cops << endl;
			cout << "Введите сколько элементов добавлять\n";
			int s; cin >> s;
			for (int i = 0; i < s; i++)
			{
				cin >> m1;
				k = add_file(file_name, rubs, cops, m1);
				if (k < 0) cout << "Не удается прочитать файл\n";
				if (k == 0) k = add_end(file_name, m1);
			}
			cout << "Добавлено " << s << " элементов\n";
			break;
		case 5: cout << "Введите название файла\n";
			cin >> file_name;
			long rubss; int copss; cout << "Введите значение рублей и копеек\n"; cin >> rubss; cin >> copss;
			cout << rubss << "," << copss << endl;
			Money m2(1,50);
			k = change_file(file_name, rubss, copss, m2);
			if (k < 0) cout << "Не удается прочитать файл\n";
			if (k == 0) cout << "Пустой файл\n";
			break;
		}
	} while (c != 0);
}