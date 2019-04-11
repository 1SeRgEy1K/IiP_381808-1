#include <cmath>
#include <clocale>
#include <iomanip>
#include <iostream>
#include "Shagomer.h"
#include "Windows.h"
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_CTYPE, "Russian");
	int M1 = 10;
	int Y1 = 1950;
	int D1 = 24;
	Pedometer B(100);
	Pedometer A(Y1, M1, D1);
	try {
		B.newPodschet(1950, 10, 24, 10, 10, 11, 10, 3000);
		B.newPodschet(1950, 10, 25, 10, 10, 11, 11, 4000);
		B.newPodschet(1950, 10, 26, 10, 10, 11, 11, 5000);
		B.newPodschet(1950, 11, 26, 10, 10, 11, 11, 7000);
		B.newPodschet(1950, 12, 26, 10, 10, 11, 11, 2000);
		int menu;
		cout << "1 узнать начальную дату посчетов" << endl;
		cout << "2 добавить подсчет" << endl;
		cout << "3 получить информацию о подсчете по дате и интервалу времени" << endl;
		cout << "4 среднее число шагов в выбранном месяце" << endl;
		cout << "5 среднее число шагов за всю историю наблюдений" << endl;
		cout << "6 максимальное число шагов в выбранный месяц и дата" << endl;
		cout << "7 максимальное число шагов в день за всю историю наблюдений и дата" << endl;
		cout << "8 завершить работу" << endl;
		while (true) {
			cin >> menu;
			switch (menu)
			{
			case 1: { int Ye, M, D;
				A.DateSTART(Ye, M, D);
				cout <<  "дата начала " << Ye << '.' <<M << '.' <<D<< endl;
				break;
			}
			case 2: {
				B.newPodschet(1950, 11, 25, 10, 10, 11, 11, 10000);
				break;
			}
			case 3: {
				cout << B.getInf(1950, 10, 25, 10, 10, 11, 11) << endl;
				break;
			}
			case 4: {
				cout << B.AveregePedoMonth(10) << endl;
				break;
			}
			case 5: {
				cout << B.AveregePedoHistory() << endl;
				break;
			}
			case 6: {
				cout << B.MaxPedoMonth(10)<<"day" << B.DateMaxPedoMon(10)<<endl;
				break;
			}
			case 7: {int D, M, Year;
				B.DateMaxPedo(Year, D, M);
				cout << B.MaxPedoHistory() << " date " << D << "." << M << "." << Year << endl;
				break;
			}
			case 8: {
				return 0;
			}
			}
		}
		ofstream os; // поток для записи
		os.open("Pedomet.txt"); // файл для записи
		os << B  <<endl;
		os.close();
		// Чтение из потока
		//cout  << endl;
		ifstream is; // поток для чтения
		is.open("Pedomet.txt"); // файл для чтения
		is >> B ;
		is.close();
	}
	catch (Pedometer::Range)
	{
		cout << "не верная дата" << endl;
	}
	return 0;
}