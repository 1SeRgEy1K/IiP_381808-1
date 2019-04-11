#pragma once
#include <fstream> 
using namespace std;
class ProcCenter
{
private:
	int * cdNum;//номер карты
	string FIO;//Ф И О
	int * Sum;//сумма на счету
	int * Pin;//пин код
	int * ClietnCount;//количество клиентов
	bool block;//заблоктрована или нет карта

public:
	//constructors
	//po umolchaniu

	//inicializators

	//COPY

	//Destructor
	
	//работа с потоками
	friend ostream& operator<<(ostream& stream, const ProcCenter &Dr); // вывод 
	friend istream& operator>>(istream& stream, ProcCenter &Dr); // ввод из потока
	class Range//для обработки исключений
	{
	};

};