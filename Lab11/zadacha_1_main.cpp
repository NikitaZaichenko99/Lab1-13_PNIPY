#include <iostream>
#include <deque>
#include <numeric> // для accumulate
#include <algorithm> // для max_element и find

using namespace std;

// Функция для создания контейнера и заполнения его элементами
deque<int> makeDeque(int n) {
    deque<int> myDeque(n);
    for (int i = 0; i < n; ++i) {
        myDeque[i] = rand() % 100;
    }
    return myDeque;
}

// Функция для вывода элементов контейнера на экран
void printDeque(const deque<int>& myDeque) {
    for (auto element : myDeque) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    deque<int> myDeque = makeDeque(5); // создание контейнера
    printDeque(myDeque);

    // Задание 3
    // Найти максимальный элемент и добавить его в конец контейнера
    if (!myDeque.empty()) {
        auto maxElementIndex = distance(myDeque.begin(), max_element(myDeque.begin(), myDeque.end()));
        myDeque.push_back(myDeque[maxElementIndex]);
        cout << "Max element = " << myDeque[maxElementIndex] << endl;
    }
    else {
        cout << "Deque is empty" << endl;
    }
    printDeque(myDeque);

    // Задание 4
    // Найти элемент с заданным ключом и удалить его из контейнера
    int key;
    cout << "Key = ";
    cin >> key;
    auto it = find(myDeque.begin(), myDeque.end(), key);
    if (it != myDeque.end()) {
        myDeque.erase(it);
    }
    else {
        cout << "Key not found" << endl;
    }
    printDeque(myDeque);
    //int keys;
    //cout << "Key = ";
    //cin >> keys;
    //if (keys >= 0 && keys < myDeque.size()) {
    //    myDeque.erase(myDeque.begin() + keys);
    //    printDeque(myDeque);
    //}
    //else {
    //    cout << "Key not found" << endl;
    //}
    
    // Задание 5
    // К каждому элементу добавить среднее арифметическое элементов контейнера
    double srednee = accumulate(myDeque.begin(), myDeque.end(), 0.0) / myDeque.size();
    cout << "Average = " << srednee << endl;
    for (auto& element : myDeque) {
        element += static_cast<int>(srednee);
    }
    printDeque(myDeque);

    return 0;
}