#include "Polynom.h" // ����������� ��� �������
#include <cmath>
#include <fstream>
#include <Windows.h>

Polynom::Polynom()
{
	koef = 0;
}

Polynom::~Polynom()
{
	delete[]koef;
}
Polynom::Polynom(int an) // ���������� � ���������� //���� �������� ������� ��������, �� ���� ����� ������� ��� �������� +1 � ��������� ������
{//���������� ������ ��� �������� � ���������� ������ ������������� �������� � ������
	int i;
	n = an;
	koef = new double[n + 1];
	for (i = 0; i <= n; i++)
	{
		koef[i] = 0;
	}
}
Polynom::Polynom(const Polynom &f)//�����������
{
	n = f.n;
	koef = new double[n + 1];
	for (int i = 0; i <= n; i++)
		koef[i] = f.koef[i];
}

Polynom Polynom::operator+(const Polynom &t)//�������� �������� A+B
{
	int i;
	if (n >= t.n)//A>B
	{
		Polynom Z =*this;
		for (i = 0; i <=t. n; i++)
			Z.koef[i] = koef[i] + t.koef[i];
		return Z;
	}
	else//A<B
	{
		Polynom Z = t;
		for (i = 0; i <= n; i++)
			Z.koef[i] = t.koef[i] + koef[i];
		return Z;
	}
}

Polynom Polynom::operator = (const Polynom &t)//�����������
{
	if (this != &t)
	{
		delete[] koef;
		n = t.n;
		koef = new double[n + 1];
		for (int i = 0; i <= n; i++)
			koef[i] = t.koef[i];
	}
	return *this;
}
istream &operator>>(istream &stream, Polynom &c)// ������������� �������� �����
{
	int i;
	for (i = 0; i <= c.n; i++)
	{
		cout << "������� X^" << i<<": ";
		stream >> c.koef[i];
	}
	return stream;
}
ostream &operator<<(ostream &s, const Polynom &c)
{
	int p = 0, tmp = 0,p1=0;

	if (c.koef[c.n] == 1)// ��� ���� ����� �� ������ ���� � ������ "+" �� ���� �������� ������ (� ������ ���������) ���� �� ��������� � ������� ���
		s << "X^" << c.n;
	else if (c.koef[c.n] == -1)
		s << "-X^" << c.n;
	else if (c.koef[c.n] != 0)
		s << c.koef[c.n] << "X^" << c.n;

	for (int i = 1; i <= c.n; i++)//���������� p c������ ���� �� ���� � ��������
	{
		if (c.koef[i] != 0)
			p++;
	}
	p1 = p;
	for (int i = c.n - 1; i > 0; i--) {// ������� � �������������� ������ �������� � �������
		if ((c.koef[i] > 0)) {
			if ((c.koef[i] == 1) && (c.koef[i + 1] != 0) && (p1 != 1))
			{
				s << " + " << "X^" << i;
				p1--;
			}
			else
				if ((c.koef[i] == 1) && (c.koef[i + 1] == 0) && (p1 < 2))
				{
					s << "X^" << i;
					p1--;
				}

				else if (p1 < 2)
					s << c.koef[i] << "X^" << i;
				else {
					s << "+" << c.koef[i] << "X^" << i;
					p1--;
				}
		}
		else if ((c.koef[i] < 0))
		{
			if ((c.koef[i] == -1) && (c.koef[i + 1] != 0) && (p1 != 1) )
			{
				s << " - " << "X^" << i;
				p1--;
			}
			else if ((c.koef[i] == -1) && (c.koef[i + 1] == 0) && (p1 < 2))
			{
				s << " - " << "X^" << i;
				p1--;
			}
			
			else
			{
				s << " - " << (-1)*c.koef[i] << "X^" << i;
				p1--;
			}
		}
	}
	
	if ((c.koef[0] > 0) && (p != 0)) {//�������� �� ��, �� ���� �� ��� ���� ,�� ���� ������ � ������������,� �� ����� ����, 
		s << " + " << c.koef[0] << "\n";//���� �� ���� �� �������� ������
	}
	else if ((c.koef[0] < 0) && (p != 0))// �� �� ����� �� �� ���������������
	{
		s << " - " << (-1)*c.koef[0] << "\n";
	}
	else if ((c.koef[0] != 0) && (p == 0)) { s << c.koef[0] << '\n'; }// �������� ���� �� ��� �� ���� � �� ����� ����, �� ������ ��� �����,
	else if (p==0) s << c.koef[0] << '\n';
return s; //� ����� ���� �� ������ ���� �����, �� �� �������
}


Polynom Polynom::derivative() //����������� �� �// ������� ����� ������ ����������� ������ ����� ����������� � ����������, � ����� ���������
{                      // ��� ��������� � ����������  ���� ����������� ������� � i+1(������� �������� �������) �� i+1 ������� �� ���� ���� �������
	int i;
	Polynom Z(n - 1);
	for (i = 0; i <= n - 1; i++)
	{
		Z.koef[i] = (i + 1)*koef[i + 1];
	}
	return Z;
}

Polynom Polynom:: Calculate(double x,int n) {
	double res=0.0;

	Polynom C(n+1);
	for (int i = 0; i <= n; ++i) {
		C.koef[i] = koef[i];
	}
	res += C.koef[0];
	for (int i = 1; i <= n; i++)
	{
		res =res+( C.koef[i] * pow(x, i));
	}
	C.koef[0] = res;
	for (int i = 1; i <= n; i++)
	{
		C.koef[i] = 0;
	}
	return C;
}		
								
void Polynom::output_file(const Polynom &c)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	
	ofstream f("Polynom.txt", ofstream::app);
	if (f.is_open())
	{
		int p = 0, tmp = 0, p1 = 0;

		if (c.koef[c.n] == 1)// ��� ���� ����� �� ������ ���� � ������ "+" �� ���� �������� ������ (� ������ ���������) ���� �� ��������� � ������� ���
			f << "X^" << c.n;
		else if (c.koef[c.n] == -1)
			f << "-X^" << c.n;
		else if (c.koef[c.n] != 0)
			f << c.koef[c.n] << "X^" << c.n;

		for (int i = 1; i <= c.n; i++)//���������� p c������ ���� �� ���� � ��������
		{
			if (c.koef[i] != 0)
				p++;
		}
		p1 = p;
		for (int i = c.n - 1; i > 0; i--) {// ������� � �������������� ������ �������� � �������
			if ((c.koef[i] > 0)) {
				if ((c.koef[i] == 1) && (c.koef[i + 1] != 0) && (p1 != 1))
				{
					f << " + " << "X^" << i;
					p1--;
				}
				else
					if ((c.koef[i] == 1) && (c.koef[i + 1] == 0) && (p1 < 2))
					{
						f << "X^" << i;
						p1--;
					}

					else if (p1 < 2)
						f << c.koef[i] << "X^" << i;
					else {
						f << "+" << c.koef[i] << "X^" << i;
						p1--;
					}
			}
			else if ((c.koef[i] < 0))
			{
				if ((c.koef[i] == -1) && (c.koef[i + 1] != 0) && (p1 != 1))
				{
					f << " - " << "X^" << i;
					p1--;
				}
				else if ((c.koef[i] == -1) && (c.koef[i + 1] == 0) && (p1 < 2))
				{
					f << " - " << "X^" << i;
					p1--;
				}

				else
				{
					f << " - " << (-1)*c.koef[i] << "X^" << i;
					p1--;
				}
			}
		}

		if ((c.koef[0] > 0) && (p != 0)) {//�������� �� ��, �� ���� �� ��� ���� ,�� ���� ������ � ������������,� �� ����� ����, 
			f << " + " << c.koef[0] << "\n";//���� �� ���� �� �������� ������
		}
		else if ((c.koef[0] < 0) && (p != 0))// �� �� ����� �� �� ���������������
		{
			f << " - " << (-1)*c.koef[0] << "\n";
		}
		else if ((c.koef[0] != 0) && (p == 0)) { f << c.koef[0] << '\n'; }// �������� ���� �� ��� �� ���� � �� ����� ����, �� ������ ��� �����,
		else if (p == 0) f << c.koef[0] << '\n';
		f.close();
	}
	else {
		cout << "6666666666666";
	}
	
}
