#include <iostream>
#include <clocale>
#include <cmath>
#include "Vector.h"

using namespace std;

int main() {
	setlocale(LC_CTYPE, "rus");

	double a;
	int answer;
	int t = 1;
	Vector v1;
	Vector v2;
	Vector v3;

	while (t) {
		cout << "��� �� ������ �������?" << endl << "1) ������� " << endl << "2) ������� " << endl << "3) ��������� ��������� ������������ " << endl << "4) �������� �� ����� " << endl << "5) ��������� �������� �� �����" << endl;
		cin >> answer;

		if (answer == 4) {
			cout << endl << "������� ���������� ������� a: ";
			cin >> v1;

			cout << "�� ����� ����� �� ������ �������� ������? ";
			cin >> a;

		}
		else if (answer != 4 && abs(answer) < 6) {
			cout << endl << "������� ���������� ������� ������� a: ";
			cin >> v1;

			cout << "������� ���������� ������� ������� b: ";
			cin >> v2;
		}

		switch (answer) {
		case 1:
			v3 = v1 + v2;
			break;
		case 2:
			v3 = v1 - v2;
			break;
		case 3:
			 v3=v1 % v2;
			break;
		case 4:
			v3 = v1 * a;
			break;
		case 5:
			v3 = (v1 == v2);
			break;

		default:
			cout << "�� ������ �� �������";
			return 0;
		}

		cout << v3;

		cout << "������ ��������� ������ ��������?" << endl << "�� - 1" << endl << "��� - 0" << endl;
		cin >> t;
		while (t != 1 && t != 0) {
			cout << "������� 1 ��� 0 :) ";
			cin >> t;
		}
	}

	return 0;
}