#pragma once
#include "Triad.h"

//����� Time ����������� �� ������ Triad
class Time :
	public Triad
{
public:
	Time(void);//����������� ��� ����������
public:
	~Time(void);//����������
	Time(int, int, int);//����������� � �����������
	Time(const Time&); //����������� �����������
	Time& operator++();
	Time& operator=(const Time&); //�������� ������������
	bool operator>(const Time& l); //���������� �������� ���������
	bool operator<(const Time& l); //���������� �������� ���������
	bool operator>=(const Time& l); //���������� �������� ���������
	bool operator<=(const Time& l); //���������� �������� ���������
	void Set_hours(int G); //�����������
	void Set_minutes(int G); //�����������
	void Set_seconds(int G); //�����������
	int Get_hours() { return hours; } //��������
	int Get_minutes() { return minutes; } //��������
	int Get_seconds() { return seconds; } //��������
	friend istream& operator>>(istream& in, Time& l);//�������� �����
	friend ostream& operator<<(ostream& out, const Time& l); //�������� ������
protected: //��������
	int hours;
	int minutes;
	int seconds;
};

