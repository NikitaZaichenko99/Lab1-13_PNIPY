#pragma once
#include "Print.h"
#include <iostream>

using namespace std;

class Book :
	public Print
{
public:
	Book(void);
public:
	~Book(void);
	void Show();
	void ShowName();
	void Input();
	Book(string, string, int, string);
	Book(const Book&);
	int Get_Num() { return num; }
	string Get_Publ() { return publ; }
	void Set_Num(int);
	void Set_Publ(string);
	Book& operator=(const Book&);
protected:
	int num;
	string publ;
};
