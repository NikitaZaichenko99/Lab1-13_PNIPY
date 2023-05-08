#include <iostream>
#include <deque>
#include "Money.h"
#include <algorithm> 

using namespace std;

typedef deque<Money> MDeque;
Money m;

// ������� ��� �������� ���������� � ���������� ��� ����������
MDeque makeDeque(int n) {
    MDeque myDeque(n);
    for (int i = 0; i < n; ++i) {
        myDeque[i] = Money(rand() % 100, rand() % 100); // �������� ���������� ������ Money � ����������� rub � cop
    }
    return myDeque;
}

// ������� ��� ������ ��������� ���������� �� �����
void printDeque(const MDeque& myDeque) {
    for (auto element : myDeque) {
        cout << element.get_rub() << "." << element.get_cop() << " ";
    }
    cout << endl;
}

// ������� ��� ���������� ������������� �������� � ���������� ��� � ����� ����������
void findMaxElementAndPushBack(MDeque& myDeque) {
    auto maxElIter = max_element(myDeque.begin(), myDeque.end()); // ������� �������� �� ������������ �������
    myDeque.push_back(*maxElIter); // ��������� ������������ ������� � ����� ����������
}

// ������� ��� ���������� �������� � �������� ������ � �������� ��� �� ����������
void findAndRemoveByKey(MDeque& myDeque, Money key) {
    auto it = find(myDeque.begin(), myDeque.end(), key);
    if (it != myDeque.end()) {
        myDeque.erase(it);
    }
    else {
        cout << "Key not found" << endl;
    }
}

 // ������� ���������� � ������� �������� �������� ��������������� ��������� ����������
MDeque findSredneeAndPush(MDeque& myDeque)
{
    Money m = Money(0, 0);

    if (myDeque.empty()) {
        cout << "��������� ����" << endl;
    }
    else
    {
        for (int i = 0; i < myDeque.size(); i++) { m = m + myDeque[i]; }
        int n = myDeque.size();
        Money r = m / n;
        cout << "������� �������� = " << r << endl;

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
    MDeque myDeque = makeDeque(5); // �������� ����������
    cout << "���������: "; printDeque(myDeque); cout << endl;
    findMaxElementAndPushBack(myDeque); // ������� ������������ ������� � ��������� ��� � ����� ����������
    cout << "�������� ������������ ������� � �����: "; printDeque(myDeque); cout << endl; // ������� �������� ���������� �� �����
    Money key;
    cout << "������� ���� " << endl; cin >> key;
    findAndRemoveByKey(myDeque, key); // ������� ������� � �������� ������ � ������� ���
    cout << "������� ������: "; printDeque(myDeque); // ������� �������� ���������� �� �����
    findSredneeAndPush(myDeque);
    cout << "�������� � ������� ��������: "; printDeque(myDeque);
}