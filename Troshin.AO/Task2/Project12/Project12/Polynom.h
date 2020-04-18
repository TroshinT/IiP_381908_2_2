#pragma once
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
class Polynom
{
public:
	int n,m; //������� ��������
	double *koef; //��������� �� ������ ������������� �������� koef[i] - ����������� ��� i-� �������
	Polynom();
	Polynom(int an);//����������� � �����������
	Polynom(const Polynom &); //�����������
	~Polynom();//����������

	Polynom operator+(const Polynom &);   //�������� �������� ���� ���������
	Polynom operator=(const Polynom &);   //�������� ������������
	Polynom derivative();//�����������
	
	 Polynom Calculate(double x, int n);//��������� �������� � ����� �
	void output_file(const Polynom &c);

	friend ostream &operator<< (ostream &s, const Polynom &c); // ������������� �������� ������
	friend istream &operator >> (istream &s, Polynom &c); // ������������� �������� �����

};