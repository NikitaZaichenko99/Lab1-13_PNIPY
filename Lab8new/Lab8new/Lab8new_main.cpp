#include "Book.h"
#include "List.h"
#include "Object.h"
#include "Print.h"
#include "Dialog.h"
#include "Event.h"
#include <windows.h>
#include <iostream>


using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите команду\nДоступные команды: " << endl;
	cout << "m создать группу\n+ добавить объект в группу\n- удалить объект из группы\n";
	cout << "s просмотр группы\nz просмотр имени группы по индексу\nq конец работы\n";
	Dialog D;
	D.Execute();
}