#pragma once
#include "Object.h"
#include <iostream>

class List
{
public:
    List();
    List(int);
    ~List();
    void Add();
    void HandleEvent(const TEvent& e);
    void Remove(int index);
    void PrintName(int k);
    void Del();
    void Show();
    int operator()();
protected:
    struct Node
    {
        Object* data; // ������ ��������
        Node* next; // ��������� �� ��������� �������
        Node(Object* dat, Node* n = nullptr) : data(dat), next(n) {}
    };
    Node* head; // ��������� �� ������ ������� ������
    int size; // ������ ������
    int cur; // ������� �������
};