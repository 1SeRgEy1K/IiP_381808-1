#pragma once
#include <fstream> 
#include <string>
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
	int y_st;//год начала
	int m_st;//месяц
	int d_st;//день
public:
	//constructors
	Pedometer();//po umolchaniu
	//inicializators
	Pedometer(int bufsize_);
	Pedometer(int Y_st, int M_st, int D_st);
	//COPY
	Pedometer(const Pedometer &Dr);
	//Destructor
	~Pedometer();
	void DateSTART(int &Yst, int &Mst, int &Dst);
	void newPodschet(int y, int m, int d, int Hs, int Ms, int He, int Me, int ped);
	int getInf(int y, int m, int d, int Hs, int Ms, int He, int Me);
	int AveregePedoMonth(int mon);
	int AveregePedoHistory();
	int MaxPedoMonth(int Mon);
	int MaxPedoHistory();
	int DateMaxPedoMon(int Mon);
	void DateMaxPedo(int &y, int &d, int&m);
	//работа с потоками
	friend ostream& operator<<(ostream& stream, const Pedometer &Dr); // вывод 
	friend istream& operator>>(istream& stream, Pedometer &Dr); // ввод из потока
	class Range//для обработки исключений
	{
	};

};