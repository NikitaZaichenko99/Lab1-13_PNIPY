#include "Print.h"
#include <iostream>

using namespace std;

Print::Print(void) { title = ""; author = ""; }
Print::~Print(void) {}
Print::Print(string M, string C) { title = M; author = C; }
Print::Print(const Print& Print) { title = Print.title; author = Print.author; } 
void Print::Set_title(string C) { title = C; }
void Print::Set_author(string M) { author = M; }
Print& Print::operator=(const Print& c)
{
	if (&c == this)return *this;
	title = c.title;
	author = c.author;
	return *this;
}
void Print::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)//событие-сообщение
	{
		switch (e.command)
		{
		case cmGet:cout << "title = " << Get_title() << endl;
			break;
		}
	}
}
void Print::Show()
{
	cout << "\ntitle: " << title;
	cout << "\nauthor: " << author;
	cout << "\n";
}
void Print::ShowName()
{
	cout << "\ntitle: " << title;
	cout << "\n";
}
void Print::Input()
{
	cout << "\ntitle: "; cin >> title;
	cout << "author: "; cin >> author;
}