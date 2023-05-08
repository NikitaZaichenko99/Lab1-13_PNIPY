#include "Time.h"

//конструктор без параметров
Time::Time(void) :Triad() { hours = 0; minutes = 0; seconds = 0; }
//конструктор с параметрами
Time::Time(int hours, int minutes, int seconds) :Triad(hours, minutes, seconds)
{
	this->hours = hours; this->minutes = minutes; this->seconds = seconds;
}
//конструктор копирования
Time::Time(const Time& L)
{
	hours = L.hours; minutes = L.minutes; seconds = L.seconds;
}
//дестрктор
Time::~Time(void) {}
//модификаторы
void Time::Set_hours(int H){ hours = H; }
void Time::Set_minutes(int M){ minutes = M; }
void Time::Set_seconds(int S){ seconds = S; }
//оперция присваивания
Time& Time::operator=(const Time& l)
{
	if (&l == this)return *this;
	hours = l.hours; minutes = l.minutes; seconds = l.seconds;
	return *this;
}
//перегрузка префиксной операции инкремент
Time& Time::operator++()
{
	while (seconds > 60) { minutes += 1; seconds -= 60; }
	while (minutes > 60) { hours += 1;minutes -= 60; }
	return *this;
}
//перегрузка операции сравнения >
bool Time::operator>(const Time& l) {
    if (hours > l.hours) { return true; }
    else if (hours == l.hours && minutes > l.minutes) { return true; }
    else if (hours == l.hours && minutes == l.minutes && seconds > l.seconds) { return true; }
    else { return false; }
}
//перегрузка операции сравнения <
bool Time::operator<(const Time& l) {
    if (hours < l.hours) { return true; }
    else if (hours == l.hours && minutes < l.minutes) { return true; }
    else if (hours == l.hours && minutes == l.minutes && seconds < l.seconds) { return true; }
    else { return false; }
}
//перегрузка операции сравнения >=
bool Time::operator>=(const Time& l) {
    if (hours > l.hours) { return true; }
    else if (hours == l.hours && minutes > l.minutes) { return true; }
    else if (hours == l.hours && minutes == l.minutes && seconds > l.seconds) { return true; }
    else if (hours == l.hours && minutes == l.minutes && seconds == l.seconds) { return true; }
    else { return false; }
}
//перегрузка операции сравнения <=
bool Time::operator<=(const Time& l) {
    if (hours < l.hours) { return true; }
    else if (hours == l.hours && minutes < l.minutes) { return true;}
    else if (hours == l.hours && minutes == l.minutes && seconds < l.seconds) { return true; }
    else if (hours == l.hours && minutes == l.minutes && seconds == l.seconds) { return true; }
    else { return false; }
}
//операция ввода
istream& operator>>(istream& in, Time& l)
{
	cout << "\nhours: "; in >> l.hours;
    cout << "minutes: "; in >> l.minutes;
	cout << "seconds: "; in >> l.seconds;
	return in;
}
//операция вывода
ostream& operator<<(ostream& out, const Time& l)
{
	out << "\nTime: " << l.hours << " : " << l.minutes << " : " << l.seconds;
	return out;
}