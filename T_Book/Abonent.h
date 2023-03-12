#pragma once
#include<iostream>

using namespace std;

class Abonent
{
	char* _FIO;
	int _h_phone;
	int _w_phone;
	int _m_phone;
	char _add_info[25];
	friend class FileBook;
public:
	Abonent(char* fio, int h, int w, int m, const char* add) :
		_FIO{ (fio) ? new char[strlen(fio) + 1] : new char[30] },
		_h_phone{ h }, _w_phone{ w }, _m_phone{ m }
	{
		strcpy_s(_add_info, add);
		if (fio) strcpy_s(_FIO, strlen(fio) + 1, fio);
	}
	Abonent() : Abonent(nullptr, 0, 0, 0, "\0") { }
	//~Abonent() { delete[]_FIO; }

	static void Print(Abonent book[], int s);
	static void findFIO(Abonent book[], int count, char* fio);

	static void deleteAbonent(Abonent book[], int* s, int index);

	static void Add(Abonent book[], int* s);
};

