#pragma once
using namespace std;
class Date
{
public:
	Date();
	//inicializators
	Date::Date(int Y_st, int M_st, int D_st);
	Date(const Date &D);
	~Date();
	int Date::StartY();
	int Date::StartM();
	int Date::StartD();
	friend ostream& operator<<(ostream& stream, const Date &Dr); // вывод 
	friend istream& operator>>(istream& stream, Date &Dr); // ввод из потока
private:
int y_st;//год начала
	int m_st;//месяц
	int d_st;//день
};
