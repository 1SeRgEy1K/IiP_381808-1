#include <cmath>
#include <clocale>
#include <fstream>
#include <string>
#include "ProcCenter.h"
using namespace std;
proccenter::proccenter() {
	cdNum = block = Pin = Sum = 0;
	FIO = "0";
}
proccenter::~proccenter() {
	cdNum = block = Pin = Sum = 0;
	FIO = "0";
}
ostream& operator<<(ostream& stream, const proccenter &B)
{
	stream << B.FIO << " " << B.Sum << " " << B.cdNum << " " << B.Pin << " " << B.block << endl;
	return stream;
}
istream& operator>>(istream& stream, proccenter &B)
{
	stream >> B.FIO >> B.Sum >> B.cdNum >> B.Pin >> B.block;
	return stream;
}
