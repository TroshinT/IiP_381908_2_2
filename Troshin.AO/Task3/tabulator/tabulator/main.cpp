#include "Tabulator.h" 
int main() {
	setlocale(LC_ALL, "Russian");
	Tabulator x;
	int x1, a1, b1, n1, m;
	cout � "1.���� �������� ������������� [a, b] � �������� ���������� ����� ���������"�endl�"2.������ ����� ����� ������������� n"�endl�"3.������ �������� �������������"�endl�"4.������ ����� ����� �������������"�endl�"5.��������� ������������� �������"�endl�"6.��������� �������� �������������� ������� � �������� ����� x � �������� ��� �������� �� ��������� �������� ������� � ���� �����"�endl�"7.��������� ������"�endl;

	do {
		cin � m;
		switch (m) {
		case 1:
			cout � "������� �������� ������������� a � b" � endl;
			cin � a1 � b1;
			cout � a1 � b1;
			x.interval(a1, b1);
			break;
		case 2:
			cout � "������� ����� ����� ������������� n" � endl;
			cin � n1;
			x.num(n1);
			break;
		case 3:
			float s[2];
			x.interval1(s[0], s[1]);
			cout � s[1] � s[0];

			break;
		case 4:
			int n0;
			n0 = x.num1();
			cout � n0;
			break;
		case 5:
			x.tab();

			break;
		case 6:


			break;
		}
	} while (m != 7);





	return 0;
}
