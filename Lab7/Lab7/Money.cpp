#include "Money.h"

bool Money::operator==(const Money& m)
{
    if (rub == m.rub && cop == m.cop) { return true; }
    else { return false; }
}
Money& Money::operator=(const Money& m)
{
    if (&m == this) return *this;
    rub = m.rub;
    cop = m.cop;
    return *this;
}
bool Money::operator<(const Money& a) const {
    if (rub < a.rub)
        return true;
    else if (rub == a.rub && cop < a.cop)
        return true;
    else
        return false;
}
bool Money::operator!=(const Money& a) const {
    if (rub != a.rub || cop != a.cop)
        return true;
    else
        return false;
}
ostream& operator<<(ostream& out, const Money& a) {
    out << a.rub << "," << a.cop;
    return out;
}
istream& operator>>(istream& in, Money& a) {
    cout << "Введите рубли = "; in >> a.rub;
    cout << "Введите копейки = "; in >> a.cop;
    cout << endl;
    return in;
}
//Money& Money::operator++()
//{
//    long e = rub + (cop / 100);
//    rub = e;
//    cop = cop % 100;
//    return *this;
//}