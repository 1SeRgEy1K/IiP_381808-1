#include <cmath>
#include <clocale>
#include <iomanip>
#include <iostream>
#include "Tabulator.h"
//opisanie/////////////////////////////////////////////////////////////////////////////////////
using namespace std;
double ff1(double x)
{
	return cos(x);
}
double ff2(double x)
{
	return sin(x);
}
double ff3(double x)
{
	return x*x;
}
double ff4(double x)
{
	if (x >= 0)
		return sqrt(x);
	else
	{
		cout << "введено не корректное значение" << endl;
		abort();
	}
}
Tabulator::Tabulator()//po umolchaniu
{
	a = b = n = 0;
	X = NULL;
	f = NULL;
}
//inicializators
Tabulator::Tabulator(int num, double a_, double b_)
{	a = a_;
	b = b_;
	n = num;
	f = new double[n];
	X = new double[n];
	
}
//COPY
Tabulator::Tabulator(const Tabulator &Dr)
{

	n = Dr.n;
	f = new double[n];
	for (int i = 0; i < n; i++)
		f[i] = Dr.f[i];
	X = new double[n];
	for (int i = 0; i < n; i++)
	X[i] = Dr.X[i];
}
Tabulator::~Tabulator()//Destructor
{
	if (X != NULL) {
		delete[] X;
		X = NULL;
	}
	if (f != NULL) {
		delete[] f;
		f = NULL;
		}
	a = 0;
	b = 0;
	n = 0;
}
// вывод в поток 
ostream& operator<<(ostream& stream, const Tabulator &Dr)
{
	//stream << Dr.a << Dr.b << " ";
	stream << Dr.n << " ";//количество точек табулирования
	for (int i = 0; i < Dr.n; i++)
	{
		stream << Dr.X[i] << " ";
	}
	stream << endl;
	for (int i = 0; i < Dr.n; i++)
	{
		stream << Dr.f[i] << " ";
	}
	stream << endl;
	return stream;
}
//ввод в поток
istream& operator>>(istream& stream, Tabulator &Dr)
{
	int str;
	stream >> str;
	if (Dr.n != str)
	{
		if (Dr.X != NULL)
			delete[] Dr.X;
		Dr.n = str;
		Dr.X = new double[str];
	}
	if (Dr.n != str)
	{
		if (Dr.f != NULL)
			delete[] Dr.f;
		Dr.n = str;
		Dr.f = new double[str];
	}
	for (int i = 0; i < Dr.n; i++)
	{
		stream >> Dr.X[i];
		}
	for (int i = 0; i < Dr.n; i++)
	{
		stream >> Dr.f[i];
	}
	return stream;
}
//задать интервал 
void Tabulator::INTERVAL(double _a, double _b)
{
	a = _a; b = _b;
}
void Tabulator::Tochki(int _n)
{
	n = _n;
}
double Tabulator::INTER1()
{
	return a;
}
double Tabulator::INTER2()
{
	return b;
}
int Tabulator::Tochki1()
{
	return n;
}
void Tabulator::Tabulirovanie(Tfun _fun)
{
	fun = _fun;
	double step;
	if (a > b)
	{
		step = fabs(a - b)/(n+1);
		for (int j = 0; j < n; j++)
		{   b += step;
			X[j] = b;
			f[j] = fun(X[j]);
				}
	}
	else
	{
		step = fabs(b - a) / (n+1);
		for (int j = 0; j < n; j++)
		{   a += step;
			X[j] = a;
			f[j] = fun(X[j]);
			
		}
	}
}
void Tabulator::show(const char* name1, const char* name2)
{
	cout << name1 << ": ";
	for (int i = 0; i < n; i++)
		cout<< setw(10) << X[i]<<"|" << "\t";//табуляция
	cout << "\n_____________________________________________________________________________________________________" << endl;
	cout << name2 << ": ";
	for (int i = 0; i < n; i++)
		cout << setw(10) << f[i]<<"|" << "\t";//табуляция
cout << endl;
}