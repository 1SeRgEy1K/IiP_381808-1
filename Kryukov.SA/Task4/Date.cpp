#include <cmath>
#include <clocale>
#include <iomanip>
#include <iostream>
#include "Date.h"
//opisanie/////////////////////////////////////////////////////////////////////////////////////
using namespace std;
Date::Date(){
	y_st = m_st = d_st = 0;//начала
}
//inicializators
Date::Date(int Y_st, int M_st, int D_st){
	y_st = Y_st;
	m_st = M_st;
	d_st = D_st;
}
Date::Date(const Date &D){//copy
	y_st = D.y_st;
	m_st = D.m_st;
	d_st = D.d_st;
}
Date::~Date(){//Destructor
	y_st = 0;
	m_st = 0;
	d_st = 0;
}
//узнать начальные дату и время
int Date::StartY() {
	return y_st;
}
int Date::StartM() {
	return m_st;
}
int Date::StartD() {
	return d_st;
}
// вывод в поток 
ostream& operator<<(ostream& stream, const Date &Dr){
	stream << Dr.y_st << " "<<Dr.d_st<< " "<<Dr.m_st ;
	stream << endl;
	return stream;
}
//ввод в поток
istream& operator>>(istream& stream, Date &Dr){
	int str;
	stream >> str;
	return stream;
}