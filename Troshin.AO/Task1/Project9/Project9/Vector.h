#pragma once
#pragma once

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class Vector {
private:
	double x, y, z;                               // ����������

public:
	double choice;
	void newchoice(const  int a);
	Vector();                                     // �� ���������
	Vector(double _x, double _y, double _z);      // ������������� �������
	Vector(double a);                             // �������������� ����
	Vector(const Vector& v);                      // �����������
	~Vector();                                    // ����������

	friend std::ostream& operator<<(std::ostream& stream, const Vector& v);
	friend std::istream& operator>>(std::istream& stream, Vector& v);

	bool CompVector(const Vector& v);

	Vector &operator=(const Vector& v);//������������

	Vector operator+(const Vector& v);
	Vector operator-(const Vector& v);
	Vector operator%(const Vector& v);//��������� ������������
	Vector operator*(const double &v);//��������� �� ������
	bool operator==(const Vector& v);//��������� ����
};