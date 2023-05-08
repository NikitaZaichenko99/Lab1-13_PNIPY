#include "Book.h"

Book::Book(void) :Print() { num = 0; publ = ""; }
Book::~Book(void) {}
Book::Book(string M, string C, int P, string G) :Print(M, C) { num = P; publ = G; }
Book::Book(const Book& L)
{
	title = L.title;
	author = L.author;
	num = L.num;
	publ = L.publ;
}
void Book::Set_Num(int P) { num = P; }
void Book::Set_Publ(string G) { publ = G; }
Book& Book::operator=(const Book& l)
{
	if (&l == this)return *this;
	title = l.title;
	author = l.author;
	return *this;
}
void Book::Show()
{
	cout << "\ntitle: " << title;
	cout << "\nauthor: " << author;
	cout << "\nnum: " << num;
	cout << "\npubl: " << publ;
	cout << "\n";
}
void Book::ShowName()
{
	cout << "\ntitle: " << title;
	cout << "\n";
}
void Book::Input()
{
	cout << "\ntitle: "; cin >> title;
	cout << "author: "; cin >> author;
	cout << "num: "; cin >> num;
	cout << "publ: "; cin >> publ;
}