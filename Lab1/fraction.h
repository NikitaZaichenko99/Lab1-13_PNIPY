#pragma once
struct fraction
{
	double first;
	double second;
	void Init(double, double);//метод для инициализации полей
	void Read();//метод для чтения значений полей
	void Show();//метод для вывода значений полей
	double Distation(fraction, fraction);//метод вычисления расстояния
};
