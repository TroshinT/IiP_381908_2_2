#include <iostream>
#include "Vector.h"



Vector::Vector() {
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

Vector::Vector(double _x, double _y, double _z) : x(_x), y(_y), z(_z) { }// �������������

Vector::Vector(double a) {//�������������� ����
	this->x = a;
	y = 0.0;
	z = 0.0;
}

Vector::Vector(const Vector& v) {//�����������
	x = v.x;
	y = v.y;
	z = v.z;
}

Vector::~Vector() {//����������
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

std::ostream& operator<<(std::ostream& stream, const Vector& v) {//�����
	stream << "�����: ";
	if ((v.x != 0) && (v.y == 0) && (v.z == 0)) {
		stream << v.x << endl << endl;
	}
	else {
		stream << "(" << v.x << ":" << v.y << ":" << v.z << ")" << endl << endl;
	}
	return stream;
}

std::istream& operator>>(std::istream& stream, Vector& v) {//����
	stream >> v.x >> v.y >> v.z;
	return stream;
}

// ������������
Vector& Vector :: operator= (const Vector& v) {
	this->x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

// ��������
Vector Vector :: operator+ (const Vector& v) {
	Vector vec;
	vec.x = x + v.x;
	vec.y = y + v.y;
	vec.z = z + v.z;
	return vec;
}

// ���������
Vector Vector :: operator- (const Vector& v) {
	Vector vec;
	vec.x = x - v.x;
	vec.y = y - v.y;
	vec.z = z - v.z;
	return vec;
}

// ��������� ������������
Vector Vector :: operator% (const Vector& v) {
	Vector vec;
	double res=0.0;
	vec.x = x * v.x;
	vec.y = y * v.y;
	vec.z = z * v.z;
	res = vec.x + vec.y + vec.z;
	return res;
}

// ��������� ������� �� ������
Vector Vector :: operator* (const double& v) {
	Vector vec;
	vec.y = y * v;
	vec.x = x * v;
	vec.z = z * v;
	return vec;
}

bool Vector :: operator== (const Vector& v) {
	return ((v.x == x) && (v.y == y) && (v.z == z));
}

bool Vector::CompVector(const Vector& v) {
	bool res = 0;
	double v1 = abs(sqrt(this->x * x + y * y + z * z));
	double v2 = abs(sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
	if (v1 == v2) res = 1;

	return res;
}