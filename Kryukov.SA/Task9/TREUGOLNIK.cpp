// ����� �����������
#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;
class Treugolnik {
public:

	double a, b, c, p, S, P, max, id;
	void get()
	{
		cout << "\n������� ������� �; ";
		cin >> a;
		cout << "\n������� ������� b; ";
		cin >> b;
		cout << "\n������� ������� �; ";
		cin >> c;
	}
	void Existence()
	{
		id = 0;
		if (a >= b + c || b >= a + c || c >= a + b)
		{
			cout << "\n������������ �� ����������:";
			id = 1;
		}
		else
			cout << "\n����������� ����������:";
	}
	void square()
	{
		p = (a + b + c) / 2;
		S = sqrt(p*(p - a)*(p - b)*(p - c));
		cout << "\n������� ������������=: " << S;
	}
	void perimeter()
	{
		P = a + b + c;
		cout << "\n�������� ������������=: " << P;
	}
	void type()
	{
		if (a >= b && a >= c)
			max = a;
		if (b >= a && b >= c)
			max = b;
		if (c >= b && c >= a)
			max = c;

		if (a == max && max < sqrt(b*b + c * c) || b == max && max < sqrt(a*a + c * c) || c == max && max < sqrt(b*b + a * a))
			cout << "\n����������� ������������� ";
		if (a == max && max == sqrt(b*b + c * c) || b == max && max == sqrt(a*a + c * c) || c == max && max == sqrt(b*b + a * a))
			cout << "\n����������� ������������ ";
		if (a == max && max > sqrt(b*b + c * c) || b == max && max > sqrt(a*a + c * c) || c == max && max > sqrt(b*b + a * a))
			cout << "\n����������� ������������ ";
	}


};


int main()
{
	setlocale(LC_ALL, "ru");
	int V;

	Treugolnik K;
	K.get();

	K.Existence();
	V = K.id;
	if (V != 1)
	{
		K.square();
		K.perimeter();
		K.type();
	}
	getchar();
	getchar();
}
