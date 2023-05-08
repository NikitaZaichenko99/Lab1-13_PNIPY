#include <iostream>
#include <stack>
#include <vector>
#include <C:\Users\nikit\source\repos\zadacha_2/Money.h>

using namespace std;
typedef stack<Money>St;//стек
typedef vector<Money>Vec;//вектор

St make_stack(int n)
{
	St s;
	Money m;
	for (int i = 0; i < n; i++)
	{
		cin >> m;//ввод переменной
		s.push(m);//добавление ее в стек
	}
	return s;//вернуть стек как результат функции
}
//копирует стек в вектор
Vec copy_stack_to_vector(St s)
{
	Vec v;
	while (!s.empty())//пока стек не пустой
	{
		//добавить в вектор элемент из вершиы стека
		v.push_back(s.top());
		s.pop();
	}
	return v; //вернуть вектор как результат функции
}
//копирует вектор в стек
St copy_vector_to_stack(Vec v)
{
	St s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);//добавить в стек элемент вектора
	}
	return s; //вернуть стек как результат функции
}
//Вывод стека
void print_stack(St s)
{
	while (!s.empty()) // пока стек не пустой
	{
		cout << s.top() << " "; // выводим верхний элемент стека
		s.pop(); // удаляем верхний элемент из стека
	}
	cout << endl; // переходим на новую строку
}
//вычисление среднего значения
Money Srednee(St s)
{
	Vec v = copy_stack_to_vector(s);//копируем стек в вектор
	int n = 1;
	Money sum = s.top();//начальное значениедля суммы
	s.pop();//удалить первый элемент из вектора
	while (!s.empty())//пока стек не пустой
	{
		sum = sum + s.top();//добавить в сумму элемент из вершины стека
		s.pop();//удалить элемент
		n++;
	}
	s = copy_vector_to_stack(v);//скопировать вектор в стек
	return sum / n; //вернуть среднее арифметическое
}
//поиск максимального элемента в стеке
Money Max(St s)
{
	Money m = s.top();//переменной m присваиваем значение из вершины стека
	Vec v = copy_stack_to_vector(s);//копируем стек в вектор
	while (!s.empty())//пока стк не пустой
	{
		if (s.top() > m)m = s.top();//срвниваем m и элемнт в вершине стека
		s.pop();//удаляем элемент из стека
	}
	s = copy_vector_to_stack(v);//копиуем вектор в стек
	return m; //возвращаем m
}
//добавление элемента в стек
void Add_to_stack(St& s, Money el, int pos)
{
	Vec v;
	Money t;
	int i = 1;//номер элемента в стеке
	while (!s.empty())//пока стек не пустой
	{
		t = s.top();//получить элемент из вершины
		//если номер равен номеру позиции, на котоую добвляем элемент
		if (i == pos)v.push_back(el);//добавить новый элемент в вектор
		v.push_back(t);//добавить элемент из стека в вектор
		s.pop();//удалить элемент из стека
		i++;
	}
	s = copy_vector_to_stack(v);//копируем вектор в стек
}
//Нахождение элемента с заданным ключом и удаление его из контейнера
bool removeByKey(St& stack, const Money& k) {
	St tempStack; // временный стек для хранения элементов
	bool found = false; // флаг, указывающий на то, найден ли элемент
	while (!stack.empty()) {
		Money m = stack.top();
		stack.pop();
		if (m == k) {
			found = true;
			break;
		}
		else {
			tempStack.push(m);
		}
	}
	while (!tempStack.empty()) {
		stack.push(tempStack.top());
		tempStack.pop();
	}
	return found;
}
//добавление среднего арифметического контейнера к каждому элементу
void addAverageToStack(St& stack, const Money& t) {
	Vec vec;
	while (!stack.empty()) {
		Money m = stack.top();
		stack.pop();
		vec.push_back(m);
	}
	for (const auto& m : vec) {
		Money M = t + m;
		stack.push(M);
	}
}
void main()
{
	setlocale(LC_ALL, "rus");
	Money m, t;
	St s;
	int n, a; long r; int c;
	cout << "Введите n = "; cin >> n;
	s = make_stack(n);
	print_stack(s);
	m = Max(s);
	cout << "Максимальный элемент = " << m << endl;
	s.push(m); //добавление в конец очереди
	print_stack(s);
	cout << "Введите рубли и копейки для ключа: " << endl;
	cin >> r; cin >> c;
	Money q(r, c);
	if (removeByKey(s, q)) cout << "Элемент " << q << " найден и удален" << endl;
	else cout << "Элемент не найден" << endl;
	print_stack(s);
	t = Srednee(s);
	cout << "Среднее значение " << t << endl << "Добавили к каждому элементу" << endl;
	addAverageToStack(s, t);
	print_stack(s);
}