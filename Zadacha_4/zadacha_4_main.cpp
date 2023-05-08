#include <iostream>
#include <stack>
#include <vector>
#include <C:\Users\nikit\source\repos\zadacha_2/Money.h>

using namespace std;
typedef stack<Money>St;//����
typedef vector<Money>Vec;//������

St make_stack(int n)
{
	St s;
	Money m;
	for (int i = 0; i < n; i++)
	{
		cin >> m;//���� ����������
		s.push(m);//���������� �� � ����
	}
	return s;//������� ���� ��� ��������� �������
}
//�������� ���� � ������
Vec copy_stack_to_vector(St s)
{
	Vec v;
	while (!s.empty())//���� ���� �� ������
	{
		//�������� � ������ ������� �� ������ �����
		v.push_back(s.top());
		s.pop();
	}
	return v; //������� ������ ��� ��������� �������
}
//�������� ������ � ����
St copy_vector_to_stack(Vec v)
{
	St s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);//�������� � ���� ������� �������
	}
	return s; //������� ���� ��� ��������� �������
}
//����� �����
void print_stack(St s)
{
	while (!s.empty()) // ���� ���� �� ������
	{
		cout << s.top() << " "; // ������� ������� ������� �����
		s.pop(); // ������� ������� ������� �� �����
	}
	cout << endl; // ��������� �� ����� ������
}
//���������� �������� ��������
Money Srednee(St s)
{
	Vec v = copy_stack_to_vector(s);//�������� ���� � ������
	int n = 1;
	Money sum = s.top();//��������� ����������� �����
	s.pop();//������� ������ ������� �� �������
	while (!s.empty())//���� ���� �� ������
	{
		sum = sum + s.top();//�������� � ����� ������� �� ������� �����
		s.pop();//������� �������
		n++;
	}
	s = copy_vector_to_stack(v);//����������� ������ � ����
	return sum / n; //������� ������� ��������������
}
//����� ������������� �������� � �����
Money Max(St s)
{
	Money m = s.top();//���������� m ����������� �������� �� ������� �����
	Vec v = copy_stack_to_vector(s);//�������� ���� � ������
	while (!s.empty())//���� ��� �� ������
	{
		if (s.top() > m)m = s.top();//��������� m � ������ � ������� �����
		s.pop();//������� ������� �� �����
	}
	s = copy_vector_to_stack(v);//������� ������ � ����
	return m; //���������� m
}
//���������� �������� � ����
void Add_to_stack(St& s, Money el, int pos)
{
	Vec v;
	Money t;
	int i = 1;//����� �������� � �����
	while (!s.empty())//���� ���� �� ������
	{
		t = s.top();//�������� ������� �� �������
		//���� ����� ����� ������ �������, �� ������ �������� �������
		if (i == pos)v.push_back(el);//�������� ����� ������� � ������
		v.push_back(t);//�������� ������� �� ����� � ������
		s.pop();//������� ������� �� �����
		i++;
	}
	s = copy_vector_to_stack(v);//�������� ������ � ����
}
//���������� �������� � �������� ������ � �������� ��� �� ����������
bool removeByKey(St& stack, const Money& k) {
	St tempStack; // ��������� ���� ��� �������� ���������
	bool found = false; // ����, ����������� �� ��, ������ �� �������
	while (!stack.empty()) {
		Money m = stack.top();
		stack.pop();
		if (m == k) {
			found = true;
			break;
		}
		else {
			tempStack.push(m);
		}
	}
	while (!tempStack.empty()) {
		stack.push(tempStack.top());
		tempStack.pop();
	}
	return found;
}
//���������� �������� ��������������� ���������� � ������� ��������
void addAverageToStack(St& stack, const Money& t) {
	Vec vec;
	while (!stack.empty()) {
		Money m = stack.top();
		stack.pop();
		vec.push_back(m);
	}
	for (const auto& m : vec) {
		Money M = t + m;
		stack.push(M);
	}
}
void main()
{
	setlocale(LC_ALL, "rus");
	Money m, t;
	St s;
	int n, a; long r; int c;
	cout << "������� n = "; cin >> n;
	s = make_stack(n);
	print_stack(s);
	m = Max(s);
	cout << "������������ ������� = " << m << endl;
	s.push(m); //���������� � ����� �������
	print_stack(s);
	cout << "������� ����� � ������� ��� �����: " << endl;
	cin >> r; cin >> c;
	Money q(r, c);
	if (removeByKey(s, q)) cout << "������� " << q << " ������ � ������" << endl;
	else cout << "������� �� ������" << endl;
	print_stack(s);
	t = Srednee(s);
	cout << "������� �������� " << t << endl << "�������� � ������� ��������" << endl;
	addAverageToStack(s, t);
	print_stack(s);
}