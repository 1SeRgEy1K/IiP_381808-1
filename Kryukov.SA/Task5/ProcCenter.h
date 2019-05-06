#pragma once
using namespace std;

class proccenter
{
private:
	int  cdNum;//номер карты
	string FIO;//Ф И О
	int Sum;//сумма на счету
	int Pin;//пин код
	bool block;//заблоктрована или нет карта
	//прочее методы и конструкторы
public:
	proccenter();
	~proccenter();
	friend ostream& operator<<(ostream& stream, const proccenter &Dr); // вывод 
	friend istream& operator>>(istream& stream, proccenter &Dr); // ввод из потока

	friend class Bankomatt;
};