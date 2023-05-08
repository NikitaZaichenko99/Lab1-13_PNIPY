#pragma once
#include "iostream"

using namespace std;

class Iterator
{
	friend class Set;//дружественный класс
public:
	Iterator() { elem = 0; }//конструктор без параметров
	Iterator(const Iterator& it) { elem = it.elem; }//конструктор копирования
	int& operator *() const { return*elem; } //перегруженная операция разыменования
	Iterator operator+(int n) const { auto copy = *this; advance(copy.elem, n); return copy; } //переход вправо к элементу с номером n 
private:
	int* elem; //указатель на элемент типа int
};

class Set
{
public:
	Set(int s, int k = 0); //конструктор с параметрами: выделяет память под s элементов и заполняет их значением k
	Set(const Set& a); //конструктор с параметрами
	~Set(); //деструктор
	Set& operator=(const Set& a); //оператор присваивания
	int& operator[](int index); //операция доступа по индексу
	Set operator+(const int k); //операция для добавление константы
	int operator()(); //операция, возвращающая длину множества
	bool operator<(int value) const; //проверка принадлежности числа множеству
	bool operator!=(const Set& ); // проверка на неравенство
	friend ostream& operator<<(ostream& out, const Set& a); //перегруженные операции вывода
	friend istream& operator>>(istream& in, Set& a); //перегруженные операции ввода
	Iterator first() { return beg; } //возвращает указатель на первый элемент
	Iterator last() { return end; } //возвращает указатель на элемент следующий за последним
private:
	int size; //размер множества
	int* data; //укзатель на динамический массив значений множества
	Iterator beg; //указатель на первый элемент множества
	Iterator end; //указатель на элемент следующий за последним
};
