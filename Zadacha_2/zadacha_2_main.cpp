#include "Money.h"
#include <cstdlib>
#include <deque>

using namespace std;
typedef deque<Money>Deq;

Deq make_deque(int n)
{
	Deq d;
	for (int i = 0; i < n; i++)
	{
		long r = rand() % 100000; 
		int c = rand() % 100; 
		Money m(r, c); 
		d.push_back(m);
	}
	return d;
}

void print_deque(Deq d)
{
	for (int i = 0; i < d.size(); i++)
		cout << d[i] << " ";
	cout << endl;
}

// Найти максимальный элемент и добавить его в конец контейнера
void Max(Deq& d)
{
    if (d.empty()) {
        cout << "Контейнер пуст" << endl;
        return;
    }

    Money max_element = d.front();
    for (int i = 0; i < d.size(); i++) {
        if (d[i] > max_element) {
            max_element = d[i];
        }
    }
    cout << "Максимальный элемент = " << max_element << endl;
    d.push_back(max_element);
}

// Найти элемент с заданным ключом и удалить его из контейнера
void remove(Deq& d, Money key)
{
    int index = -1;
    for (int i = 0; i < d.size(); i++) {
        if (d[i] == key) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        d.erase(d.begin() + index);
        cout << "Элемент удален" << endl;
    }
    else {
        cout << "Элемент не найден" << endl;
    }
}
//void remove(Deq& d, int key)
//{
//    if (key >= 0 && key < d.size()) {
//        d.erase(d.begin() + key);
//        cout << "Элемент удален." << endl;
//    }
//    else {
//        cout << "Элемент не найден." << endl;
//    }
//}

Deq average(Deq& d)
{
    Money m = Money(0, 0);
   
    if (d.empty()) {
        cout << "Контейнер пуст" << endl;
    }
    else
    {
        for (int i = 0; i < d.size(); i++) { m = m + d[i]; }
        int n = d.size();
        Money r = m / n;
        cout << "Среднее значение = " << r << endl;

        for (int i = 0; i < d.size(); i++) {
          d[i] = r + d[i];
        }
        return d;
    }
}

int main()
{
    long r; int c;
    srand(time(0));
	setlocale(LC_ALL, "rus");
	Deq d = make_deque(10);
	cout << "Исходный контейнер: ";
	print_deque(d);
	Max(d);
	print_deque(d);
    cout << "Введите рубли и копейки для ключа: " << endl;
    cin >> r; cin >> c;
    Money s(r, c);
    remove(d, s);
    print_deque(d);
    average(d);
    print_deque(d);
}