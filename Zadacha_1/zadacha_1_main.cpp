#include <iostream>
#include <deque>
#include "Money.h"
#include <algorithm> 

using namespace std;

typedef deque<Money> MDeque;
Money m;

// Функция для создания контейнера и заполнения его элементами
MDeque makeDeque(int n) {
    MDeque myDeque(n);
    for (int i = 0; i < n; ++i) {
        myDeque[i] = Money(rand() % 100, rand() % 100); // создание экземпляра класса Money с параметрами rub и cop
    }
    return myDeque;
}

// Функция для вывода элементов контейнера на экран
void printDeque(const MDeque& myDeque) {
    for (auto element : myDeque) {
        cout << element.get_rub() << "." << element.get_cop() << " ";
    }
    cout << endl;
}

// Функция для нахождения максимального элемента и добавления его в конец контейнера
void findMaxElementAndPushBack(MDeque& myDeque) {
    auto maxElIter = max_element(myDeque.begin(), myDeque.end()); // находим итератор на максимальный элемент
    myDeque.push_back(*maxElIter); // добавляем максимальный элемент в конец контейнера
}

// Функция для нахождения элемента с заданным ключом и удаления его из контейнера
void findAndRemoveByKey(MDeque& myDeque, Money key) {
    auto it = find(myDeque.begin(), myDeque.end(), key);
    if (it != myDeque.end()) {
        myDeque.erase(it);
    }
    else {
        cout << "Key not found" << endl;
    }
}

 // Функция добавления к каждому элементу среднего арифметического элементов контейнера
MDeque findSredneeAndPush(MDeque& myDeque)
{
    Money m = Money(0, 0);

    if (myDeque.empty()) {
        cout << "Контейнер пуст" << endl;
    }
    else
    {
        for (int i = 0; i < myDeque.size(); i++) { m = m + myDeque[i]; }
        int n = myDeque.size();
        Money r = m / n;
        cout << "Среднее значение = " << r << endl;

        for (int i = 0; i < myDeque.size(); i++) {
            myDeque[i] = r + myDeque[i];
        }
        return myDeque;
    }
}

int main() 
{
    setlocale(LC_ALL, "rus");
    int n;
    MDeque myDeque = makeDeque(5); // создание контейнера
    cout << "Контейнер: "; printDeque(myDeque); cout << endl;
    findMaxElementAndPushBack(myDeque); // находим максимальный элемент и добавляем его в конец контейнера
    cout << "Добавили максимальный элемент в конец: "; printDeque(myDeque); cout << endl; // выводим элементы контейнера на экран
    Money key;
    cout << "Введите ключ " << endl; cin >> key;
    findAndRemoveByKey(myDeque, key); // находим элемент с заданным ключом и удаляем его
    cout << "Удалили элемнт: "; printDeque(myDeque); // выводим элементы контейнера на экран
    findSredneeAndPush(myDeque);
    cout << "Добавили к каждому элементу: "; printDeque(myDeque);
}