#include<iostream>
#include<iomanip>
#include<fstream>
#include "Polynom.h"

int main()
{
	setlocale(LC_ALL, "");
	int n,c, m;
	double x;
	cout << "������ ��������� ������������? 1- �� �����, 2- � ����������" << endl;
	cin >> c;
	cout << "������� ������� �������� A � ������� �������� B:" << '\n';
	cin >> n >> m;
	Polynom A(n);
	Polynom B(m);
	Polynom D;
	Polynom C;
	ifstream ifs;
	ofstream ofs;
	switch(c) {
		case 1:
			ifs.open("Polynom.txt");

			if (!ifs.is_open())
			{
				cout << "������ ����� ";
			}
			else
			{

				ifs >> x;
				ifs >> A;
				ifs >> B;

			}
			break;
		case 2:
			cout << "������� ����������� �������� A:" << '\n';
			cin >> A;
			cout << "������� ����������� �������� B:" << '\n';
			cin >> B;
			cout << "������� �������� �:" << '\n';
			cin >> x;

	}
	
	
	cout << "��������� �:" << A << '\n';
	cout << "��������� B:" <<  B << '\n';
	D = A + B;
	cout << "��������� D=A+B:" << D.zeropow() << '\n';
	
	cout << "����������� �� A:" << A.derivative() << '\n';

	

	cout << "�������� �������� � ����� " << x << " = "<< A.Calculate(x) <<'\n';
	ofs.open("Polynom.txt");
	ofs << "��������� �:" << A<<"\n";
	ofs << "��������� B:" << B<<"\n";
	ofs << "��������� D=A+B:" << D << "\n";
	ofs << "����������� �� A : " << A.derivative() << "\n";
	ofs << "�������� �������� � ����� " << x << " = " << A.Calculate(x) << "\n";
	ofs.close();
	
	system("pause");
}