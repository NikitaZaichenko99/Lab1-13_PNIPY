#include <iostream>
#include <deque>
#include <numeric> // ��� accumulate
#include <algorithm> // ��� max_element � find

using namespace std;

// ������� ��� �������� ���������� � ���������� ��� ����������
deque<int> makeDeque(int n) {
    deque<int> myDeque(n);
    for (int i = 0; i < n; ++i) {
        myDeque[i] = rand() % 100;
    }
    return myDeque;
}

// ������� ��� ������ ��������� ���������� �� �����
void printDeque(const deque<int>& myDeque) {
    for (auto element : myDeque) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    deque<int> myDeque = makeDeque(5); // �������� ����������
    printDeque(myDeque);

    // ������� 3
    // ����� ������������ ������� � �������� ��� � ����� ����������
    if (!myDeque.empty()) {
        auto maxElementIndex = distance(myDeque.begin(), max_element(myDeque.begin(), myDeque.end()));
        myDeque.push_back(myDeque[maxElementIndex]);
        cout << "Max element = " << myDeque[maxElementIndex] << endl;
    }
    else {
        cout << "Deque is empty" << endl;
    }
    printDeque(myDeque);

    // ������� 4
    // ����� ������� � �������� ������ � ������� ��� �� ����������
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
    
    // ������� 5
    // � ������� �������� �������� ������� �������������� ��������� ����������
    double srednee = accumulate(myDeque.begin(), myDeque.end(), 0.0) / myDeque.size();
    cout << "Average = " << srednee << endl;
    for (auto& element : myDeque) {
        element += static_cast<int>(srednee);
    }
    printDeque(myDeque);

    return 0;
}