#include<iostream>
#include<iomanip>
#include<fstream>
#include "Polynom.h"

int main()
{
	setlocale(LC_ALL, "");
	int n, m;
	double x;
	cout << "������� ������� �������� A � ������� �������� B:" << '\n';
	cin >> n >> m;
	Polynom A(n);
	Polynom B(m);
	Polynom D;
	Polynom C;
	Polynom test;
	cout << "������� ����������� �������� A:" << '\n';
	cin >> A;
	cout << "������� ����������� �������� B:" << '\n';
	cin >> B;
	cout << "������� �������� �:" << '\n';
	cin >> x;
	
	cout << "��������� �:" << A << '\n';
	cout << "��������� B:" <<  B << '\n';
	cout << "��������� D=A+B:" << (D = A + B) << '\n';
	
	cout << "����������� �� A:" << A.derivative() << '\n';

	

	cout << "�������� �������� � ����� " << x << " = "<< A.Calculate(x, n) <<'\n';
	test.output_file(A);
	test.output_file(B);
	test.output_file(D);

	system("pause");
}