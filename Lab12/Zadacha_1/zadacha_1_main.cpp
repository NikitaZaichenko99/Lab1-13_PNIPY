#include <iostream>
#include <set>
#include <algorithm> 
#include <numeric> 

using namespace std;

typedef set<int> TSet; 
TSet::iterator i; 

TSet make_set(int n)
{
    TSet s; 
    int a;
    for (int i = 0; i < n; i++)
    {
        cout << "Введите значение: "; 
        cin >> a;
        s.insert(a); 
    }
    return s; 
}

void print_set(TSet s)
{
    for (auto i = s.begin(); i != s.end(); i++)
        cout << *i << " ";
    cout << endl;
}

void add_max_element(TSet s)
{
    if (s.empty()) return;
    int max_elem = *max_element(s.begin(), s.end()); 
    cout << "Максимальный элемент = " << max_elem << ". ";
    s.insert(max_elem); 
}

TSet remove_element(TSet s, int key)
{
    auto it = s.find(key);
    if (it != s.end()) s.erase(it);
    return s;
}

TSet add_average(TSet& s)
{
    int average = accumulate(s.begin(), s.end(), 0) / s.size();
    cout << "Средние значение = " << average << endl;
    TSet e;
    transform(s.begin(), s.end(), inserter(e, e.end()),
        [average](int element) { return element + average; });
    return e;
}
int main()
{
    setlocale(LC_ALL, "rus");
    int n;

    TSet s = make_set(5); 
    cout << "Элементы: ";
    print_set(s);

    add_max_element(s); 
    cout << "Максимальный элемент добавлен в конец: ";
    print_set(s);

    cout << "Ключ =  "; cin >> n;
    s = remove_element(s, n);
    cout << "Элемент удален: ";
    print_set(s);

    s = add_average(s);
    cout << "Добавлено среднее значение: ";
    print_set(s); 

    return 0;
}