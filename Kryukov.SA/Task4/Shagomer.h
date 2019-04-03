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
	int h_st;//час
	int min_st;//минута начала
public:
	//constructors
	Pedometer();//po umolchaniu
	//inicializators
	Pedometer::Pedometer(int bufsize_);
	Pedometer::Pedometer(int Y_st, int M_st, int D_st, int H_st, int MIN_st);
	//COPY
	Pedometer::Pedometer(const Pedometer &Dr);
	//Destructor
	~Pedometer();
	void Pedometer::DateSTART(int &Yst, int &Mst, int &Dst, int &Hst, int &Minst);
	void Pedometer::newPodschet(int y, int m, int d, int Hs, int Ms, int He, int Me, int ped);
	int Pedometer::getInf(int y, int m, int d, int Hs, int Ms, int He, int Me);
	int Pedometer::AveregePedoMonth(int mon);
	int Pedometer::AveregePedoHistory();
	int Pedometer::MaxPedoMonth(int Mon);
	int Pedometer::MaxPedoHistory();
	int Pedometer::DateMaxPedoMon(int Mon);
	void Pedometer::DateMaxPedo(int &d, int&m);
	//работа с потоками
	friend ostream& operator<<(ostream& stream, const Pedometer &Dr); // вывод 
	friend istream& operator>>(istream& stream, Pedometer &Dr); // ввод из потока
	class Range//для обработки исключений
	{
	};

};