#include <iostream>
#include <set>
#include <algorithm> 
#include <numeric> 
#include "Money.h"

using namespace std;

typedef set<Money> TSet;

TSet make_set(int n)
{
    TSet s;
    Money a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        s.insert(a);
    }
    return s;
}

void print_set(const TSet& s)
{
    for (auto i = s.begin(); i != s.end(); i++)
        cout << *i << " ";
    cout << endl;
}

void add_max_element(TSet& s)
{
    if (s.empty()) return;
    Money max_m = *max_element(s.begin(), s.end());
    cout << "Максимальный элемент = " << max_m << ". ";
    s.insert(max_m);
}

TSet remove_element(TSet& s, const Money& key)
{
    auto it = s.find(key);
    if (it != s.end()) s.erase(it);
    return s;
}

TSet add_average(TSet& s)
{
    Money sum = accumulate(s.begin(), s.end(), Money(0, 0));
    Money average = sum / s.size();
    cout << "Средние значение = " << average << endl;
    TSet e;
    transform(s.begin(), s.end(), inserter(e, e.end()),
        [average](Money element) { return element + Money(average); });
    return e;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int n = 5, c;
    long r;
    TSet s = make_set(n);
    print_set(s);

    add_max_element(s);
    cout << "Максимальный элемент добавлен в конец: ";
    print_set(s);

    cout << "Ведите рубли и копейки для ключа " << endl;
    cin >> r; cin >> c;
    cout << "Ключ = " << r << "," << c << endl;
    Money q(r, c);
    s = remove_element(s, q);
    cout << "Элемент удален: ";
    print_set(s);

    s = add_average(s);
    cout << "Среднее добавлено к элементам: ";
    print_set(s);

    return 0;
}
