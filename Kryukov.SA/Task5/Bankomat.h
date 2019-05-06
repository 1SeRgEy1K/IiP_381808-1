#pragma once
using namespace std;
#include"ProcCenter.h"
class Bankomatt
{
private:
	const int maxBuf = 2000;//максимальное количество купюр одного достоинства
	int Count[6];//кол-во достоинств купюр
	const int MaxcupGive = 40;//максимум выдачи за 1 операцию
	int  ClietnCount;//максимальное количество клиентов
	int realCl;//реальное количество клиентов
	static const int n = 5;// переменная на котрую будет увеличиваться буфер
	proccenter * klient;//массив клиетов банка
public:
	Bankomatt();
	Bankomatt(const Bankomatt &Dr);
	~Bankomatt();
	bool FindCL(int cdNum_);//найти клиента по номеру карты
	int getMany(int sum_, int cdNum_);//снять наличные
	int giveMany(int sum, int cdNum_);//внести 
	void Print(int cdNum_);//вывести на печатающее устройство
	void PrintConsole(int cdNum_, int &sum);//показать счет на экране
	void BlockCD(int cdNum_);//блокировка карты
	bool CheckBlock(int cdNum_);//проверка заблок. карта или нет
	proccenter inputCARD(int PIN, int cdNum_);//принять карту 
	bool checkPin(int cdNum, int Pin);//верный или нет пин код

	friend ostream& operator << (ostream & stream, Bankomatt const  &B);
	friend istream & operator >> (istream & stream, Bankomatt &B);
	class Range//для обработки исключений
	{
	};

};