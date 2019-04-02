#include <cmath>
#include <clocale>
#include <iomanip>
#include <iostream>
#include "Shagomer.h"
#include "Date.h"
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
}
Pedometer::Pedometer(int bufsize_, int leng_){//инициализатор
	leng = leng_;
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
Pedometer::Pedometer(const Pedometer &Dr){//копирование
	bufsize = Dr.bufsize;
	leng = Dr.leng;
	pedo = new int[bufsize];
	Y = new int[bufsize];
	mon = new int[bufsize];
	Day = new int[bufsize];
	Hstar= new int[bufsize];
	Mstar = new int[bufsize];
	Hend = new int[bufsize];
	Mend = new int[bufsize];
	for (int i = 0; i < bufsize; i++){
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
//добавить подсчет
void Pedometer::newPodschet(int y, int m, int d, int Hs, int Ms, int He, int Me, int ped ) {
	
	if (leng <= bufsize && m < 13 && m>0 && d > 0 && d < 32 && Hs >= 0 && Hs < 24 && Ms >= 0 && Ms < 60 && He >= 0 && He < 24 && Me >= 0 && Me < 60 && ped >= 0)
	{

		for (int i = leng; i < leng + 1; i++)
		{
			Y[i] = y;
			mon[i] = m;
			Day[i] = d;
			Hstar[i] = Hs;
			Mstar[i] = Ms;
			Hend[i] = He;
			Mend[i] = Me;
			pedo[i] = ped;

		}
		leng++;
	}
	else
		throw Range();
}
//получить информ о нужном подсчете 
int Pedometer::getInf (int y, int m, int d, int Hs, int Ms, int He, int Me) {
	for(int i =0; i <leng; i++)
		if (y == Y[i] && m == mon[i] && d == Day[i] && Hs == Hstar[i] && Ms == Mstar[i] && He == Hend[i] && Me == Mend[i])
		{
			return pedo[i];
		}
		else 
			throw Range();
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
int Pedometer::DateMaxPedoM() {
	int num;
	int PEDO = 0;
	for (int i = 0; i <leng; i++)
		if (pedo[i] > PEDO)
		{
			PEDO = pedo[i];
			num = mon[i];
		}
	return num;

}
int Pedometer::DateMaxPedoD() {
	int num;
	int PEDO = 0;
	for (int i = 0; i <leng; i++)
		if (pedo[i] > PEDO)
		{
			PEDO = pedo[i];
			num = Day[i];
		}
	return num;

}
ostream& operator<<(ostream& stream, const Pedometer &Dr) {
	stream << Dr.leng << " " << Dr.bufsize << " ";
	
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
	if (Dr.bufsize != str){
		if (Dr.Y != NULL)
			delete[] Dr.Y;
		Dr.bufsize = str;
		Dr.Y = new int[str];
	}
	if (Dr.bufsize != str){
		if (Dr.Day != NULL)
			delete[] Dr.Day;
		Dr.bufsize = str;
		Dr.Day = new int[str];
	}
	if (Dr.bufsize != str){
		if (Dr.mon != NULL)
			delete[] Dr.mon;
		Dr.bufsize = str;
		Dr.mon = new int[str];
	}	
	if (Dr.bufsize != str){
		if (Dr.Hend != NULL)
			delete[] Dr.Hend;
		Dr.bufsize = str;
		Dr.Hend = new int[str];
	}
	if (Dr.bufsize != str){
		if (Dr.Hstar != NULL)
			delete[] Dr.Hstar;
		Dr.bufsize = str;
		Dr.Hstar = new int[str];
	}
	if (Dr.bufsize != str) {
		if (Dr.Mstar != NULL)
			delete[] Dr.Mstar;
		Dr.bufsize = str;
		Dr.Mstar = new int[str];
	}
	if (Dr.bufsize != str) {
		if (Dr.Mend != NULL)
			delete[] Dr.Mend;
		Dr.bufsize = str;
		Dr.Mend = new int[str];
	}
	if (Dr.bufsize != str) {
		if (Dr.pedo != NULL)
			delete[] Dr.pedo;
		Dr.bufsize = str;
		Dr.pedo = new int[str];
	}
	for (int i = 0; i < Dr.bufsize; i++){
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