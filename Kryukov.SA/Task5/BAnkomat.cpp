#include <cmath>
#include <clocale>
#include <fstream>
#include <string>
#include "Bankomat.h"
using namespace std;
Bankomatt::Bankomatt()
{
	for (int i = 0; i < 6; ++i)
		Count[i] = 1600;
	klient = nullptr;
	ClietnCount = 3;
	realCl = 0;
}
Bankomatt::Bankomatt(const Bankomatt &B) {
	ClietnCount = B.ClietnCount;
	realCl = B.realCl;
	klient = new proccenter[B.ClietnCount];
	for (int i = 0; i < B.realCl; ++i)
		klient[i] = B.klient[i];
}
Bankomatt::~Bankomatt()
{
	realCl = 0;
	if (klient != nullptr) {
		delete[] klient;
		klient = nullptr;
	}
}

ostream& operator << (ostream & stream, Bankomatt const &B) {
	stream << B.realCl << endl;
	for (int i = 0; i < B.realCl; i++) {
		stream << B.klient[i];
	}
	return stream;
}
istream & operator >> (istream & stream, Bankomatt &B) {
	stream >> B.realCl;
	while (B.realCl >= B.ClietnCount) {
		delete[]B.klient;
		B.ClietnCount += B.n;
		B.klient = new proccenter[B.ClietnCount];//cm
	}
	for (int i = 0; i < B.realCl; ++i) {
		stream >> B.klient[i];
	}

	return stream;
}
//узнать не заблокирована ли карта
bool Bankomatt::CheckBlock(int cdNum_) {
	for (int i = 0; i < realCl; ++i) {
		if (klient[i].cdNum == cdNum_)
			if (klient[i].block == 1)
				return 0;
			else return 1;
	}
}
//заблоктровать карту
void Bankomatt::BlockCD(int cdNum_) {
	for (int i = 0; i < realCl; ++i) {
		if (klient[i].cdNum == cdNum_)
			klient[i].block = 1;
	}
}
//снять наличные
int Bankomatt::getMany(int sum, int cdNum_) {
	for (int i = 0; i < 6; i++)
		if (Count[i] == 0)
			throw Range();
	for (int i = 0; i < realCl; ++i) {
		klient[i].Sum = klient[i].Sum - sum;
		return klient[i].Sum;
	}
}
//внести наличные 
int Bankomatt::giveMany(int sum, int cdNum_) {
	for (int i = 0; i < 6; i++)
		if (Count[i] > maxBuf)
			throw Range();
	for (int i = 0; i < realCl; ++i)
		if (klient[i].cdNum == cdNum_ && sum % 100 == 0 && sum < 200001)
		{
			klient[i].Sum = klient[i].Sum + sum;
			return klient[i].Sum;
		}
		else throw Range();
}
//принять карту 
proccenter Bankomatt::inputCARD(int PIN, int cdNum_) {
	if (Bankomatt::checkPin(cdNum_, PIN) == Bankomatt::FindCL(cdNum_)) {
		for (int i = 0; i < realCl; ++i)
			if (klient[i].Pin == PIN)
				return klient[i];
	}
}
//найти клиента по номеру карты
bool Bankomatt::FindCL(int cdNum_)
{
	for (int i = 0; i < realCl; ++i)
		if (klient[i].cdNum == cdNum_)
			return 1;
		else return 0;
}
// проверить пин код
bool Bankomatt::checkPin(int cdNum_, int Pin_) {
	for (int i = 0; i < realCl; ++i) {
		if (klient[i].cdNum == cdNum_ && klient[i].block == 0)
			if (klient[i].Pin == Pin_)
				return 1;
			else return 0;
	}
}

//напечатать на принтере состояние счета владельца в банке 
void Bankomatt::Print(int cdNum_) {
	for (int i = 0; i < realCl; ++i)
		if (klient[i].cdNum == cdNum_)
		{
			ofstream outfile;
			outfile.open("PRN");
			outfile << klient[i].Sum << endl;
			outfile << '\x0C';
		}
}
//показать счет клиента на консоли
void Bankomatt::PrintConsole(int cdNum_, int &sum) {
	for (int i = 0; i < realCl; ++i)
		if (klient[i].cdNum == cdNum_)
		{
			sum = klient[i].Sum;
		}
}