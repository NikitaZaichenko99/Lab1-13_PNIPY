#include "List.h"
#include "Object.h"
#include "Book.h"
#include "Print.h"

List::List() { head = nullptr; size = 0; cur = 0; }
List::List(int s)
{
    head = nullptr;
    size = 0;
    cur = 0;
    for (int i = 0; i < s; i++)
    {
        Object* p = nullptr;
        Node* temp = new Node(p, head);
        head = temp;
        size++;
    }
}
List::~List()
{
    while (head)
    {
        Node* temp = head->next;
        delete head;
        head = temp;
    }
}
void List::Add()
{
    Object* p;
    cout << "1. Print " << endl;
    cout << "2. Book " << endl;
    int y;
    cin >> y;
    if (y == 1)//добавление объекта класса Print
    {
        Print* a = new Print();
        a->Input();
        p = a;
        Node* temp = new Node(p, head);
        head = temp;
        size++;
    }
    if (y == 2) //добавление объекта класса Book
    {
        Book* b = new Book();
        b->Input();
        p = b;
        Node* temp = new Node(p, head);
        head = temp;
        size++;
    }
}
void List::HandleEvent(const TEvent& e)
{
    if (e.what == evMessage)
    {
        Node* current_node = head;
        while (current_node)
        {
            Object* p = static_cast<Object*>(current_node->data);
            p->HandleEvent(e);
            current_node = current_node->next;
        }
    }
}
void List::Remove(int index)
{
    if (index < 0 || index >= size) return;

    Node* temp = head;
    Node* prev = nullptr;

    // ищем элемент по индексу
    for (int i = 0; i < index; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (prev == nullptr) // удаление первого элемента
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    delete temp;
    size--;
}
void List::PrintName(int k) {
    if (k < 0 || k > size) {
        cout << "Такого элемента нет\n";
        return;
    }
    int count = 0;
    Node* temp = head;
    while (temp && count != k) {
        temp = temp->next;
        count++;
    }
    if (temp) {
        temp->data->ShowName();
    }
}
void List::Del()
{
    if (size == 0) return;
    Node* temp = head;
    head = head->next;
    delete temp;
    size--;
}
void List::Show()
{
    if (size == 0) return;
    Node* temp = head;
    while (temp)
    {
        temp->data->Show(); // вызываем метод Show() объекта
        temp = temp->next;
    }
}
int List::operator()() { return size; }