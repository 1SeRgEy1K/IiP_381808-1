#include <cmath>
#include <clocale>
#include <iomanip>
#include <iostream>
#include "Shagomer.h"
#include <utility>
//opisanie/////////////////////////////////////////////////////////////////////////////////////
using namespace std;
Pedometer::Pedometer(){//по умолчанию
	pedo = NULL;//количество шагов
	Y = NULL;;//год
	mon = NULL;//месяц
	Day = NULL;//день
	Hstar = NULL;//час начала
	Mstar = NULL;//минута начала
    Hend = NULL;//час конца
    Mend = NULL;//минута конца
    bufsize=0;//макс число подсчетов
    leng=0;//текущее число подсчетов
	y_st = m_st = d_st = h_st = min_st = 0;
}
Pedometer::Pedometer(int bufsize_){//инициализатор
	leng = 0;
	bufsize = bufsize_;
	if (leng <= bufsize) {
		pedo = new int[bufsize];
		Y = new int[bufsize];
		mon = new int[bufsize];
		Day = new int[bufsize];
		Hstar = new int[bufsize];
		Mstar = new int[bufsize];
		Hend = new int[bufsize];
		Mend = new int[bufsize];
	}
	else
		throw Range();
}
Pedometer::Pedometer(int Y_st, int M_st, int D_st, int H_st, int MIN_st) {
	y_st = Y_st;
	m_st = M_st;
	d_st = D_st;
	h_st = H_st;
	min_st = MIN_st;
}
Pedometer::Pedometer(const Pedometer &Dr){//копирование
	bufsize = Dr.bufsize;
	leng = Dr.leng;
	y_st = Dr.y_st;
	m_st = Dr.m_st;
	d_st = Dr.d_st;
	h_st =Dr.h_st;
	min_st = Dr.min_st;
	pedo = new int[bufsize];
	Y = new int[bufsize];
	mon = new int[bufsize];
	Day = new int[bufsize];
	Hstar= new int[bufsize];
	Mstar = new int[bufsize];
	Hend = new int[bufsize];
	Mend = new int[bufsize];
	for (int i = 0; i < leng; i++){
		pedo[i] = Dr.pedo[i];
		Y[i] = Dr.Y[i];
		mon[i] = Dr.mon[i];
		Day[i] = Dr.Day[i];
		Hend[i] = Dr.Hend[i];
		Mend[i] = Dr.Mend[i];
		Hstar[i] = Dr.Hstar[i];
		Mstar[i] = Dr.Mstar[i];
	}
}
Pedometer::~Pedometer(){
	leng = 0;
	bufsize = 0;
	y_st = 0;
	m_st = 0;
	d_st = 0;
	h_st = 0;
	min_st = 0;
	if (pedo != NULL) {
		delete[] pedo;
		pedo = NULL;
	}
	if (Y != NULL) {
		delete[] Y;
		Y = NULL;

	}
	if (Hstar != NULL) {
		delete[] Hstar;
		Hstar = NULL;
	}
	if (mon != NULL) {
		delete[] mon;
		mon = NULL;
		
	}
	if (Day != NULL) {
		delete[] Day;
		Day = NULL;
	}
	if (Mstar != NULL) {
		delete[] Mstar;
		Mstar = NULL;
	}
	if (Hend != NULL) {
		delete[] Hend;
		Hend = NULL;
	}
	if (Mend != NULL) {
		delete[] Mend;
		Mend = NULL;
	}
}
//узнать начальные дату и время
void Pedometer::DateSTART(int &Yst, int &Mst, int &Dst, int &Hst, int &Minst) {
	y_st = Yst;
	m_st = Mst;
	d_st = Dst;
	h_st = Hst;
	min_st = Minst;
}
//добавить подсчет
void Pedometer::newPodschet(int y, int m, int d, int Hs, int Ms, int He, int Me, int ped) {
	if (leng < bufsize && m < 13 && m>0 && d > 0 && d < 32 && Hs >= 0 && Hs < 24 && Ms >= 0 && Ms < 60 && He >= 0 && He < 24 && Me >= 0 && Me < 60 && ped >= 0)
		{
			if (leng == 0) {
				Y[leng] = y_st;
				mon[leng] = m_st;
				Day[leng] = d_st;
				Hstar[leng] = h_st;
				Mstar[leng] = min_st;
				Hend[leng] = He;
				Mend[leng] = Me;
				pedo[leng] = ped;
			}
			else  {
				Y[leng] = y;
				mon[leng] = m;
				Day[leng] = d;
				Hstar[leng] = Hs;
				Mstar[leng] = Ms;
				Hend[leng] = He;
				Mend[leng] = Me;
				pedo[leng] = ped;
				}
			
			leng++;
		}
	else if (leng == bufsize && m < 13 && m>0 && d > 0 && d < 32 && Hs >= 0 && Hs < 24 && Ms >= 0 && Ms < 60 && He >= 0 && He < 24 && Me >= 0 && Me < 60 && ped >= 0){
		bufsize++;
			if (leng == 0) {
				Y[leng] = y_st;
				mon[leng] = m_st;
				Day[leng] = d_st;
				Hstar[leng] = h_st;
				Mstar[leng] = min_st;
				Hend[leng] = He;
				Mend[leng] = Me;
				pedo[leng] = ped;
				}
			else  {
				Y[leng] = y;
				mon[leng] = m;
				Day[leng] = d;
				Hstar[leng] = Hs;
				Mstar[leng] = Ms;
				Hend[leng] = He;
				Mend[leng] = Me;
				pedo[leng] = ped;
				}
			leng++;
		}
}
//получить информ о нужном подсчете 
int Pedometer::getInf (int y, int m, int d, int Hs, int Ms, int He, int Me) {
	for(int i=0; i <leng; i++)
		if ((y == Y[i] || y ==y_st) && ( m == mon[i]|| m == m_st )&& (d == Day[i]||d==d_st) &&( Hs == Hstar[i]||Hs == h_st) && (Ms == Mstar[i] || Ms ==min_st) && He == Hend[i] && Me == Mend[i])
		{
			return pedo[i];
		}
		else 
			return -1;
}
//cреднее число шагов в выбранном месяце
int Pedometer::AveregePedoMonth(int Mon){
	int PEDO=0;
	int num = 0;
	for (int i = 0; i <leng; i++)
		if (Mon == mon[i])
		{
			num++;
			PEDO += pedo[i];
		}
	int a = PEDO / num;
	return a ;
}

//cреднее число шагов за всю историю наблюдений
int Pedometer::AveregePedoHistory() {
	int k = 0;
	int a = 0;
	for (int i = 0; i<leng; i++){
		k+=pedo[i];
		a++;
	}
	int b = k/a;
	return b;
}
//максимальное число шагов в выбранном месяце
int Pedometer::MaxPedoMonth(int Mon) {
	int PEDO = 0;
	for (int i = 0; i <leng; i++)
		if (Mon == mon[i] && pedo[i]>PEDO)
		{
			PEDO = pedo[i];
		}
	return PEDO;
}
//дата когда достигнуто
int Pedometer::DateMaxPedoMon(int Mon) {
	int num;
	int PEDO = 0;
	for (int i = 0; i <leng; i++)
		if (Mon == mon[i] && pedo[i] > PEDO)
		{
			PEDO = pedo[i];
			num = Day[i];
		}
	return num;
	
}
//максимальное число шагов за всю историю наблюдений
int Pedometer::MaxPedoHistory() {
	int PEDO = 0;
	for (int i = 0; i <leng; i++)
		if (pedo[i] > PEDO)
		{
			PEDO = pedo[i];
		}
	return PEDO;
}
//дата
void Pedometer::DateMaxPedo(int &d, int&m) {
	int PEDO = 0;
	for (int i = 0; i < leng; i++)
				if (pedo[i] > PEDO)
				{
			  	   PEDO = pedo[i];
					m = mon[i];
					d = Day[i];
				}
}
ostream& operator<<(ostream& stream, const Pedometer &Dr) {
	stream << Dr.leng << " " << Dr.bufsize << " " << Dr.y_st << " " << Dr.d_st << " " << Dr.m_st<< " " << Dr.min_st<< " " <<Dr.h_st<< " ";
	for (int i = 0; i < Dr.leng; i++)
	{
		stream << Dr.Y[i] << " ";
		stream << Dr.mon[i] << " ";
		stream << Dr.Day[i] << " ";
		stream << Dr.Mstar[i] << " "; 
		stream << Dr.Hend[i] << " ";
		stream << Dr.Hstar[i] << " ";
		stream << Dr.Mend[i] << " ";
		stream << Dr.pedo[i] << " ";
	}
	stream << endl;
	return stream;
}
istream& operator>>(istream& stream, Pedometer &Dr)
{
	int str;
	stream >> str;
	if (Dr.bufsize<str){
	delete[] Dr.Day;
	delete[] Dr.mon;	
	delete[] Dr.Hend;
	delete[] Dr.Hstar;
	delete[] Dr.Mstar;
	delete[] Dr.Mend;
	delete[] Dr.pedo;
	delete[] Dr.Y;
		Dr.bufsize = str;
		Dr.Y = new int[str];
		Dr.Day = new int[str];
		Dr.mon = new int[str];
		Dr.Hend = new int[str];
		Dr.Hstar = new int[str];
		Dr.Mend = new int[str]; 
		Dr.Mstar = new int[str];
		Dr.pedo = new int[str];
	}
	for (int i = 0; i <=Dr.bufsize; i++){
		stream >> Dr.Y[i];
		stream >> Dr.mon[i];
		stream >> Dr.Day[i];
		stream >> Dr.Hend[i];
		stream >> Dr.Hstar[i];
		stream >> Dr.Mend[i];
		stream >> Dr.Mstar[i];
		stream >> Dr.pedo[i];
	}
	return stream;
}