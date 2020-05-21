#include "FloorScales.h"

vector<Nabludenie> date;
vector<FloorScales> date2;
Nabludenie::Nabludenie(int _day, int _mes, int _year, int _ves) {
	int day, mes, year, ves;
	day = _day;
	if (day < 1 || day > 31) throw std::logic_error("Input error: wrong number!");
	mes = _mes;
	if (mes < 1 || mes > 12) throw std::logic_error("Input error: wrong number!");
	year = _year;
	if (year < 1900 || year > 2020) throw std::logic_error("Input error: wrong number!");
	ves = _ves;
	if (ves < 1 || ves > 1000) throw std::logic_error("Input error:wrong number!");
	SetNabl(day, mes, year, ves);
}
FloorScales::FloorScales(const Nabludenie &d, string _name) {
	string sbuf;
	sbuf = _name;
	SetName(sbuf);
	date.push_back(d);
	SetNABL(date);
	date.pop_back();
}
Pers::Pers(const FloorScales &d) {
	date2.push_back(d);
	SetNABL2(date2);
	date2.pop_back();
}
FloorScales::FloorScales(vector<Nabludenie> dat, string name) {
	for (int i = 0; i < dat.size(); i++) {
		SetNABL(dat);
	}
	SetName(name);
}
void Pers::AddFloorScales() {
	system("cls");
	int day = -1, mes = -1, year = -1, ves = -1;
	string sbuf;
	cout << endl;

	cout << endl;
	cout << "���: ";
	cin >> sbuf;
	cout << endl;
	cout << "����: ";
	cout << endl;
	cout << "���� (�� 1 �� 31): ";
	while (day < 1 || day > 31) {
		cin >> day;
	}
	if (day < 1 || day > 31) throw std::logic_error("Input error:wrong number!");
	cout << "�����(�� 1 �� 12): ";
	while (mes < 1 || mes >12) {
		cin >> mes;
	}
	if (mes < 1 || mes > 12) throw std::logic_error("Input error:wrong number!");
	cout << "��� (�� 1900 �� 2020): ";
	while (year < 1900 || year > 2020) {
		cin >> year;
	}
	cout << endl;
	if (year < 1900 || year > 2020) throw std::logic_error("Input error:wrong number!");
	cout << "���(������������� �����):";
	while (ves < 1 || ves > 1000) {
		cin >> ves;
	}
	if (ves < 1 || ves > 1000) throw std::logic_error("Input error: wrong number!");
	Nabludenie bufNabl(day, mes, year, ves);
	FloorScales bufPers(bufNabl, sbuf);
	pers.push_back(bufPers);
	cout << "----------------------------------------------------------------" << endl;
	vibor();
}
void FloorScales::addnablpers() {
	system("cls");
	int day = -1, mes = -1, year = -1, ves = -1, np;
	cout << endl;
	cout << "����: ";
	cout << endl;
	cout << "���� (�� 1 �� 31): ";
	while (day < 1 || day > 31) {
		cin >> day;
	}
	if (day < 1 || day > 31) throw std::logic_error("Input error:wrong number!");
	cout << "�����(�� 1 �� 12): ";
	while (mes < 1 || mes >12) {
		cin >> mes;
	}
	if (mes < 1 || mes > 12) throw std::logic_error("Input error:wrong number!");
	cout << "��� (�� 1900 �� 2020): ";
	while (year < 1900 || year > 2020) {
		cin >> year;
	}
	cout << endl;
	if (year < 1900 || year > 2020) throw std::logic_error("Input error:wrong number!");
	cout << "���(������������� �����):";
	while (ves < 1 || ves > 1000) {
		cin >> ves;
	}
	if (ves < 1 || ves > 1000) throw std::logic_error("Input error: wrong number!");
	Nabludenie bufNabl(day, mes, year, ves);
	nabl.push_back(bufNabl);
	for (unsigned int n = 0; n < nabl.size() - 1; n++)
	{
		if (
			nabl[n].persDataDay == nabl[nabl.size() - 1].persDataDay &&
			nabl[n].persDataMes == nabl[nabl.size() - 1].persDataMes  &&
			nabl[n].persDataYear == nabl[nabl.size() - 1].persDataYear
			) {
			cout << "����� ���� ����! ������� 1 ����� ������������! (����� ������ ����� �� ���������)";
			cin >> np;
			if (np == 1) {
				nabl[n].persVes = nabl[nabl.size() - 1].persVes;
				nabl.pop_back();
			}
			else {
				nabl.pop_back();
			}

		}
	}
}
void FloorScales::input() {
	int  keyMes, keyYear;
	cout << "������� ��� � �����" << endl;
	cout << "����� ";
	cin >> keyMes;
	if (keyMes < 1 || keyMes > 12) throw std::logic_error("Input error: wrong number!");
	cout << "��� ";
	cin >> keyYear;
	if (keyYear < 1900 || keyYear > 2020) throw std::logic_error("Input error:wrong number!");
	bool t = true;

	stry.Mes = keyMes;
	stry.Year = keyYear;
}

int FloorScales::sredmes(int keyMes, int keyYear) {
	int resves, ves = 0, k = 0;

	for (unsigned int n = 0; n < nabl.size(); n++)
	{
		if (
			nabl[n].persDataMes == keyMes &&
			nabl[n].persDataYear == keyYear
			) {
			k++;
			ves = nabl[n].persVes + ves;
		}
	}
	resves = ves / k;
	return resves;
}

void FloorScales::sred_with_output(int keyMes, int keyYear) {
	int resves = sredmes(keyMes, keyYear);
	if (resves == 0) {
		cout << "������ ���� ���";
	}
	else {
		cout << "������� ��� �� ������ �����: ";
		cout << resves;
	}

}
void FloorScales::sredmes() {
	input();
	sred_with_output(stry.Mes, stry.Year);
}

int FloorScales::sredv() {
	int   ves = 0, k = 0;
	double resves;
	for (unsigned int n = 0; n < nabl.size(); n++)
	{
		k++;
		ves = nabl[n].persVes + ves;
	}
	resves = ves / k;
	return resves;
}
void FloorScales::sredv1() {

	cout << "������� ��� �� ��� �����: ";
	int resves = sredv();
	cout << resves;
}
void Pers::SredVes() {
	int v1 = -1, v2 = -1;
	cout << "1 - ����� ������� ��� �������� � ��������� ������ " << endl;
	cout << "2 - ����� ������� ��� �������� �� ��� ������� " << endl;
	while (v1 < 1 || v1 >2) {
		cin >> v1;
	}
	switch (v1) {
	case 1:
		vivodpers();
		while (v2 < 1 || v2 > pers.size()) {
			cin >> v2;
		}
		switch (v2) {
		case 1:
			pers[0].sredmes();
			break;
		case 2:
			pers[1].sredmes();
			break;
		case 3:
			pers[2].sredmes();
			break;
		case 4:
			pers[3].sredmes();
			break;
		case 5:
			pers[4].sredmes();
			break;
		}
		break;
	case 2:
		vivodpers();
		while (v2 < 1 || v2 > pers.size()) {
			cin >> v2;
		}
		switch (v2) {
		case 1:
			pers[0].sredv1();
			break;
		case 2:
			pers[1].sredv1();
			break;
		case 3:
			pers[2].sredv1();
			break;
		case 4:
			pers[3].sredv1();
			break;
		case 5:
			pers[4].sredv1();
			break;
		}
		break;
	}
	vibor();
}
int FloorScales::minmes(int keyMes, int keyYear) {
	int ves = 999999999;
	for (unsigned int n = 0; n < nabl.size(); n++) {
		if (
			nabl[n].persDataMes == keyMes &&
			nabl[n].persDataYear == keyYear
			) {
			if (ves > nabl[n].persVes) {
				ves = nabl[n].persVes;
			}
		}
	}

	return ves;
}

void FloorScales::minmes_with_output(int keyMes, int keyYear) {
	int ves = minmes(keyMes, keyYear);
	if (ves == 999999999) {
		cout << "������ ���� ���";
	}
	else {
		cout << "����������� ��� �� ������ �����: " << ves;
	}

}
void FloorScales::minmes() {
	input();
	minmes_with_output(stry.Mes, stry.Year);
}

int FloorScales::minv() {
	int  ves = 999999999;
	for (unsigned int n = 0; n < nabl.size(); n++)
	{
		if (ves > nabl[n].persVes) {
			ves = nabl[n].persVes;
		}
	}
	return ves;
}
void FloorScales::minv1() {
	int ves = minv();
	cout << "minimum weight for all time: ";
	cout << ves << endl;

}
void Pers::MinVes() {
	int v1 = -1, v2 = -1;
	cout << "1 - ����� ����������� ��� �������� � ��������� ������ " << endl;
	cout << "2 - ����� ����������� ��� �������� �� ��� ������� " << endl;
	while (v1 < 1 || v1 >2) {
		cin >> v1;
	}
	switch (v1) {
	case 1:
		vivodpers();
		while (v2 < 1 || v2 > pers.size()) {
			cin >> v2;
		}
		switch (v2) {
		case 1:
			pers[0].minmes();
			break;
		case 2:
			pers[1].minmes();
			break;
		case 3:
			pers[2].minmes();
			break;
		case 4:
			pers[3].minmes();
			break;
		case 5:
			pers[4].minmes();
			break;
		}
		break;
	case 2:
		vivodpers();
		while (v2 < 1 || v2 > pers.size()) {
			cin >> v2;
		}
		switch (v2) {
		case 1:
			pers[0].minv1();
			break;
		case 2:
			pers[1].minv1();
			break;
		case 3:
			pers[2].minv1();
			break;
		case 4:
			pers[3].minv1();
			break;
		case 5:
			pers[4].minv1();
			break;
		}
		break;
	}
	vibor();
}
int FloorScales::maxmes1(int keyMes, int keyYear) {
	int resves, ves = -1;

	for (unsigned int n = 0; n < nabl.size(); n++)
	{
		if (
			nabl[n].persDataMes == keyMes &&
			nabl[n].persDataYear == keyYear
			) {
			if (ves < nabl[n].persVes) {
				ves = nabl[n].persVes;

			}
		}
	}

	return ves;
}

void FloorScales::max_with_output(int keyMes, int keyYear) {
	int ves = maxmes1(keyMes, keyYear);
	if (ves == -1) {
		cout << "������ ���� ���";
	}
	else {
		cout << "������������ ��� �� ������ �����: ";
		cout << ves;
	}

}
void FloorScales::maxmes() {
	input();
	max_with_output(stry.Mes, stry.Year);
}

int FloorScales::maxv() {
	int  ves = -1;
	for (unsigned int n = 0; n < nabl.size(); n++)
	{
		if (ves < nabl[n].persVes) {
			ves = nabl[n].persVes;
		}
	}
	return ves;
}
void FloorScales::maxv1() {
	int ves = maxv();
	cout << "������������ ��� �� ��� �����: ";
	cout << ves;


}
void Pers::MaxVes() {
	int v1 = -1, v2 = -1;
	cout << "1 - ����� ������������ ��� �������� � ��������� ������ " << endl;
	cout << "2 - ����� ������������ ��� �������� �� ��� ������� " << endl;
	while (v1 < 1 || v1 >2) {
		cin >> v1;
	}
	switch (v1) {
	case 1:
		vivodpers();
		while (v2 < 1 || v2 > pers.size()) {
			cin >> v2;
		}
		switch (v2) {
		case 1:
			pers[0].maxmes();
			break;
		case 2:
			pers[1].maxmes();
			break;
		case 3:
			pers[2].maxmes();
			break;
		case 4:
			pers[3].maxmes();
			break;
		case 5:
			pers[4].maxmes();
			break;
		}
		break;
	case 2:
		vivodpers();
		while (v2 < 1 || v2 > pers.size()) {
			cin >> v2;
		}
		switch (v2) {
		case 1:
			pers[0].maxv1();
			break;
		case 2:
			pers[1].maxv1();
			break;
		case 3:
			pers[2].maxv1();
			break;
		case 4:
			pers[3].maxv1();
			break;
		case 5:
			pers[4].maxv1();
			break;
		}
		break;
	}
	vibor();
}
void Nabludenie::Print2() {
	cout << "����" << endl;
	cout << persDataDay << endl;
	cout << "�����" << endl;
	cout << persDataMes << endl;
	cout << "���" << endl;
	cout << persDataYear << endl;
	cout << "��������� ���" << endl;
	cout << persVes << endl;
}
void FloorScales::Print()
{

	cout << "���" << endl;
	cout << persName.c_str() << endl;
	nabl[0].Print2();
}


void Pers::PrintAll()
{
	system("cls");

	cout << "                   ����� ����� � ��������� ��������� " << endl;

	for (unsigned int n = 0; n < pers.size(); n++)
	{
		cout << "-------------------------------------------------" << endl;
		cout << (n + 1) << ")" << endl;
		pers[n].Print();
		cout << "-------------------------------------------------" << endl;
	}

	cout << "-------------------------------------------------\n";
	vibor();
}
void FloorScales::PrintName()
{
	cout << persName.c_str() << endl;
}

void FloorScales::PrintNabl()
{
	system("cls");
	for (unsigned int n = 0; n < nabl.size(); n++)
	{
		std::cout << "-------------------------------------------------" << std::endl;
		cout << (n + 1) << ")" << endl;
		cout << "����" << endl;
		cout << nabl[n].persDataDay << endl;
		cout << "�����" << endl;
		cout << nabl[n].persDataMes << endl;
		cout << "���" << endl;
		cout << nabl[n].persDataYear << endl;
		cout << "���" << endl;
		cout << nabl[n].persVes << endl;
		std::cout << "-------------------------------------------------" << std::endl;
	}

}
void Pers::PrintPers() {

	int v = -1;
	vivodpers();
	while (v < 1 || v > pers.size()) {
		cin >> v;
	}
	switch (v) {
	case 1: pers[0].PrintNabl();
		break;
	case 2: pers[1].PrintNabl(); break;
	case 3: pers[2].PrintNabl(); break;
	case 4: pers[3].PrintNabl(); break;
	case 5: pers[4].PrintNabl(); break;
	}
	vibor();
}
void FloorScales::Mes() {
	std::cout << "-------------------------------------------------" << std::endl;
	cout << " ���� ���������� " << endl;
	std::cout << "-------------------------------------------------" << std::endl;
	for (unsigned int n = 0; n < nabl.size(); n++)
	{
		cout << (n + 1) << endl;
		cout << nabl[n].persDataDay << ".";
		cout << nabl[n].persDataMes << ".";
		cout << nabl[n].persDataYear << endl;
		std::cout << "-------------------------------------------------" << std::endl;
	}
}

void FloorScales::Poisk() {

	vvodkeyDate();
	bool t = true;
	for (unsigned int n = 0; n < nabl.size(); n++)
	{
		if (
			nabl[n].persDataDay == stry.Day &&
			nabl[n].persDataMes == stry.Mes &&
			nabl[n].persDataYear == stry.Year
			) {
			cout << "��� : ";
			cout << nabl[n].persVes;
			t = false;
		}
	}
	if (t == true) {
		cout << "������ ���� ���";
	}
}
void FloorScales::vvodkeyDate() {

	cout << endl << "������� ������ ����" << endl;
	int  keyMes, keyYear, keyDay;
	cout << "������� ��� � �����" << endl;
	cout << "���� ";
	cin >> keyDay;
	if (keyDay < 1 || keyDay > 31) throw std::logic_error("Input error: wrong number!");
	cout << "����� ";
	cin >> keyMes;
	if (keyMes < 1 || keyMes > 12) throw std::logic_error("Input error: wrong number!");
	cout << "��� ";
	cin >> keyYear;
	if (keyYear < 1900 || keyYear > 2020) throw std::logic_error("Input error: wrong number!");
	stry.Day = keyDay;
	stry.Mes = keyMes;
	stry.Year = keyYear;
}
void Pers::dateVes() {
	system("cls");
	int v = -1;
	vivodpers();
	while (v < 1 || v > pers.size()) {
		cin >> v;
	}
	switch (v) {
	case 1:
		pers[0].Mes();
		pers[0].Poisk();
		break;
	case 2:
		pers[1].Mes();
		pers[1].Poisk();
		break;
	case 3:
		pers[2].Mes();
		pers[2].Poisk();
		break;
	case 4:
		pers[3].Mes();
		pers[3].Poisk();
		break;
	case 5:
		pers[4].Mes();
		pers[4].Poisk();
		break;
	}
	vibor();
}
void Pers::vivodpers() {
	cout << "�������� ��������" << endl;
	for (unsigned int n = 0; n < pers.size(); n++)
	{
		std::cout << "-------------------------------------------------" << std::endl;
		cout << (n + 1) << endl;
		pers[n].PrintName();
		std::cout << "-------------------------------------------------" << std::endl;
	}

}
void Pers::AddNabl() {
	system("cls");
	int v = -1;
	vivodpers();
	while (v < 1 || v > pers.size()) {
		cin >> v;
	}
	switch (v) {
	case 1: pers[0].addnablpers(); break;
	case 2: pers[1].addnablpers(); break;
	case 3: pers[2].addnablpers(); break;
	case 4: pers[3].addnablpers(); break;
	case 5: pers[4].addnablpers(); break;
	}
	vibor();
}


bool Pers::DataFromFile(string filename)
{
	SForFile sf;
	ofstream fin(filename.c_str(), ios_base::out | ios_base::binary);

	if (fin.is_open())
	{
		for (int i = 0; i < pers.size(); i++) {
			fin << pers[i].persName << endl;
			for (int j = 0; j < pers[i].nabl.size(); j++) {
				fin << pers[i].nabl[j].persDataDay << " ";
				fin << pers[i].nabl[j].persDataMes << " ";
				fin << pers[i].nabl[j].persDataYear << " ";
				fin << pers[i].nabl[j].persVes << " ";
				fin << endl;
			}
		}

		fin.close();
		return true;
	}
	return false;
}

bool Pers::DataToFile(string filename)
{
	int day = -1, mes = -1, year = -1, ves = -1;
	string sbuf;
	FloorScales bufPers;
	FloorScales bufNabl;
	int i = 0, n = 0;
	bool s = true;
	SForFile sf;
	ifstream fout(filename.c_str());
	if (fout.is_open())
	{
		while (i != 2) {
			getline(fout, sbuf);
			bufPers.SetName(sbuf);
			fout >> day;
			fout >> mes;
			fout >> year;
			fout >> ves;

			n = fout.tellg();
			fout.seekg(n + 5, ios_base::beg);
			Nabludenie bufNabl(day, mes, year, ves);
			FloorScales bufPers(bufNabl, sbuf);
			pers.push_back(bufPers);
			i++;
		}
		return true;
	}
	return false;
}
void Pers::SaveToFile()
{
	string filename;

	cout << "������� ��� �����:";
	cin >> filename;
	if (DataFromFile(filename))
	{
		system("cls");
		cout << "���������� ������� ���������.\n";
	}
	else
	{
		system("cls");
		cout << "������ ���������� � ����.\n";
	}
}
void Pers::LoadFromFile()
{
	string filename;
	cout << "������� ��� �����:";
	cin >> filename;
	if (DataToFile(filename)) {
		system("cls");
		cout << "������ ���������.\n";
	}
	else
	{
		system("cls");
		cout << "������ ������ �� �����.\n";
	}
	vibor();
}
void Pers::LoadFromFileTest(string filename)
{
	DataToFile(filename);
}
void Pers::SaveToFileTest(string filename)
{

	DataFromFile(filename);
}
void Pers::file() {
	cout << "1- ��������� � ���� " << endl;
	cout << "2 - ������� �� ����� ��������� ������ " << endl;
	int v = -1;
	while (v < 1 || v>2) {
		cin >> v;
	}
	switch (v)
	{
	case 1:
		SaveToFile();
		break;
	case 2:
		LoadFromFile();
		break;
	}
}
void Pers::vibor() {
	PrintMenu();
	int v = -1;
	while (v < 1 || v>10 || ((pers.size() < 1) && (v > 1 && v < 9))) {
		cin >> v;
	}
	switch (v) {
	case 1:
		if (pers.size() < 5) {
			AddFloorScales();
		}
		else {
			cout << "������������ ���������� ������� = 5 " << endl;
			vibor();
		}
		break;
	case 2:  PrintAll(); break;
	case 3:  AddNabl(); break;
	case 4:  PrintPers(); break;
	case 5:  dateVes(); break;
	case 6:  SredVes(); break;
	case 7:  MinVes(); break;
	case 8:  MaxVes(); break;
	case 9:  file(); break;
	case 10: exit(0); break;
	}

}
void PrintMenu()
{
	cout << endl;
	cout << "�������� ��������" << endl;
	cout << "1 - �������� ��������" << endl;
	cout << "2 - ������� ��������� ���������" << endl;
	cout << "3 - �������� ����������" << endl;
	cout << "4 - ������� ��� ��������� ���������� ��������" << endl;
	cout << "5 - ������ ��� �� ���� � �����" << endl;
	cout << "6 - ����� ������� ��� �������� � ��������� ������ ��� �� ��� �������" << endl;
	cout << "7 - ����� ����������� ��� �������� � ��������� ������ ��� �� ��� �������" << endl;
	cout << "8 - ����� ������������ ��� �������� � ��������� ������ ��� �� ��� �������" << endl;
	cout << "9 - ��������� � ���� ��� ������� �� ����� " << endl;
	cout << "10 - �����" << endl;


	std::cout << "-------------------------------------------------" << std::endl;
}