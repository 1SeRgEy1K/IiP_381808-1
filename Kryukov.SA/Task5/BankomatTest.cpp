#include <iostream>
#include <iomanip>
#include <cmath>
#include <clocale>
#include <fstream>
#include "Bankomat.h"
#include"Windows.h"
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_CTYPE, "Russian");
	try
	{
		int NUM, PinCod, summa, b;
		Bankomatt B;
		ifstream in;
		in.open("Bank.txt");
		in >> B;
		in.close();
		cout << B << endl;
		cout << "1 принять карту клиента" << endl;
		cout << "2 вернуть карту клиенту" << endl;
		while (true) {
			cin >> b;
			switch (b)
			{
			case 1:
				cout << "введите номер карты" << endl;
				cin >> NUM;
				B.FindCL(NUM);
				if (B.CheckBlock(NUM) == 1) {
					cout << "введите пин код" << endl;

					int count = 0;
					while (count < 3)
					{
						cin >> PinCod;
						B.checkPin(NUM, PinCod);
						if (B.checkPin(NUM, PinCod) == 0) {
							cout << "введен неверный пин код" << endl;
							count++;
						}
						else
							break;
					}
					if (count == 3) {
						cout << "Ваша карта заблокирована" << endl;
						B.BlockCD(NUM);
					}
					else {
						cout << B.inputCARD(PinCod, NUM) << endl;
						cout << "1 внести наличные" << endl;
						cout << "2 снять наличные" << endl;
						cout << "3 вывести состояние счета на экран" << endl;
						cout << "4 распечатать состояние счета" << endl;
						int k;
						cin >> k;

						switch (k)
						{
						case 1:
							cout << "внесите купюры" << endl;
							cin >> summa;
							cout << B.giveMany(summa, NUM) << endl;
							break;
						case 2:
							cout << "введите сумму кратную 100" << endl;
							cin >> summa;
							cout << B.getMany(summa, NUM) << endl;
							break;
						case 3:
							int a;
							B.PrintConsole(NUM, a);
							cout << " сумма на счету" << a << endl;
							break;
						case 4:
							B.Print(NUM);
							break;
						default:
							cout << "Выбрана не верная операция" << endl;
							break;
						}
					}
				}
				else
					cout << "ваша карта заблокирована" << endl;

				break;
			case 2:
				cout << "заберите карту";
				break;
			default:
				cout << "не верно выбрана функция";
			}
		}
	}
	catch (Bankomatt::Range)
	{
		cout << "не верные действия, следуйте инструкции или взаимодействия с кассетами не возможны" << endl;
	}
	getchar();
	getchar();
	return 0;
}