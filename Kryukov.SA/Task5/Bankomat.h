#pragma once
#include <fstream> 
using namespace std;
class Bankomat
{
private:
	const int maxBuf = 2000;//максимальное количество купюр одного достоинства
	int Count[6];//кол-во достоинств купюр
	const int cupGive = 40;//максимум выдачи за 1 операцию

public:
	//constructors
	//po umolchaniu
	Bankomat();
	//inicializators

	//COPY

	//Destructor

	//работа с потоками
	friend ostream& operator<<(ostream& stream, const Bankomat &Dr); // вывод 
	friend istream& operator>>(istream& stream, Bankomat &Dr); // ввод из потока
	class Range//для обработки исключений
	{
	};

};