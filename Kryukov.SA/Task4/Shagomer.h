#pragma once
#include <fstream> 
#include "Date.h"
using namespace std;
class Pedometer
{
private:
    int* pedo;//количество шагов
	int* Y;//год
	int* mon;//месяц
	int* Day;//день
	int* Hstar;//час начала
	int* Mstar;//минута начала
	int* Hend;//час конца
	int* Mend;//минута конца
	int bufsize;//макс число подсчетов 
	int leng;//текущее число подсчетов
public:
	//constructors
	Pedometer();//po umolchaniu
	//inicializators
	Pedometer::Pedometer(int bufsize_, int leng_);
	//COPY
	Pedometer::Pedometer(const Pedometer &Dr);
	//Destructor
	~Pedometer();
	void Pedometer::newPodschet(int y, int m, int d, int Hs, int Ms, int He, int Me, int ped);
	int Pedometer::getInf(int y, int m, int d, int Hs, int Ms, int He, int Me);
	int Pedometer::AveregePedoMonth(int mon);
	int Pedometer::AveregePedoHistory();
	int Pedometer::MaxPedoMonth(int Mon);
	int Pedometer::MaxPedoHistory();
	int Pedometer::DateMaxPedoMon(int Mon);
	int Pedometer::DateMaxPedoM();
	int Pedometer::DateMaxPedoD();
	//работа с потоками
	friend ostream& operator<<(ostream& stream, const Pedometer &Dr); // вывод 
	friend istream& operator>>(istream& stream, Pedometer &Dr); // ввод из потока
	class Range//для обработки исключений
	{
	};

};