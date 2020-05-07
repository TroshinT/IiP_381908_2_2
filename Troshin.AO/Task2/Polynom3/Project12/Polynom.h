#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class Polynom
{
private:
	int n; //������� ��������
	double *koef; //��������� �� ������ ������������� �������� koef[i] - ����������� ��� i-� �������

public:
		Polynom();
	Polynom(int an);//����������� � �����������
	Polynom(const Polynom &); //�����������
	~Polynom();//����������

	Polynom operator+(const Polynom &);   //�������� �������� ���� ���������
	Polynom& operator=(const Polynom &);   //�������� ������������
	
	Polynom derivative();//�����������
    double Calculate(double x);//��������� �������� � ����� �

	Polynom zeropow(Polynom );
	friend ostream &operator<< (ostream &s, const Polynom &c); // ������������� �������� ������
	friend istream &operator >> (istream &s, Polynom &c); // ������������� �������� �����

};