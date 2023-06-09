#pragma once
#include "Object.h"
#include <string>
#include <iostream>

using namespace std;

class Print :
	public Object
{
public:
	Print(void);
public:
	virtual ~Print(void);
	void Show();
	void ShowName();
	void Input();
	Print(string, string);
	Print(const Print&);
	string Get_title() { return title; }
	string Get_author() { return author; }
	void Set_title(string);
	void Set_author(string);
	Print& operator=(const Print&);
	void HandleEvent(const TEvent& e);
protected:
	string title;
	string author;
};
