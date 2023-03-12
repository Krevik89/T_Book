#pragma once
#include<iostream>
#include "Abonent.h"

using namespace std;

#define READ	"r"
#define WRITE	"w"
#define APPEND	"a"
class FileBook
{
	FILE* file;
	char* path;
	friend class Abonent;

public:
	FileBook(char* p) :path{ new char[100] } {
		strcpy_s(path, 100, p);
	}
	~FileBook() {
		delete[] path;
		fclose(file);
	}

	void SaveBookFile(Abonent*, int s);
	Abonent* LoadBookFile();
};

