#pragma once
#include <iostream>

using namespace std;

class Money {
    long rub;
    int cop;
public:
    Money(long r = 0, int c = 0) { rub = r; cop = c; }
    bool operator==(const Money& m);
    Money& operator=(const Money& m);
    bool operator<(const Money& a) const;
    bool operator!=(const Money& a) const;
    friend ostream& operator<<(ostream& out, const Money& a);
    friend istream& operator>>(istream& in, Money& a);
};