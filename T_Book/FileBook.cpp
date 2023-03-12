#include "FileBook.h"

void FileBook::SaveBookFile(Abonent* books, int size) {
	if (!fopen_s(&file, path, WRITE)) {
		for (int i{ 0 }; i < size; i++) {
			fprintf_s(file, "%s ", books[i]._FIO, strlen(books[i]._FIO) * sizeof(char));
			fprintf_s(file, "%d ", books[i]._h_phone, sizeof(int));
			fprintf_s(file, "%d ", books[i]._w_phone, sizeof(int));
			fprintf_s(file, "%d ", books[i]._m_phone, sizeof(int));
			fprintf_s(file, "%s\n ", books[i]._add_info, strlen(books[i]._add_info) * sizeof(char));
		}
	}
	fclose(file);
	printf("Информация успешно сохранена в файле \n");
}

Abonent* FileBook::LoadBookFile() {
	int count = 0;
	char* s = new char[250];
	if (!fopen_s(&file, path, READ)) {
		while (!feof(file)) {
			fgets(s, 250, file);
			count++;
		}
	}
	fclose(file);
	Abonent* books = new Abonent[count];
	int i = 0;
	char fio1[30];
	if (!fopen_s(&file, path, READ)) {
		while (!feof(file))
		{
			fscanf_s(file, "%s", fio1, sizeof(fio1));
			strcpy_s(books[i]._FIO, 30, fio1);
			fscanf_s(file, "%d", &books[i]._h_phone);
			fscanf_s(file, "%d", &books[i]._w_phone);
			fscanf_s(file, "%d", &books[i]._m_phone);
			fscanf_s(file, "%s", books[i]._add_info, sizeof(books[i]._add_info));
			i++;
		}
	}
	fclose(file);
	return books;
}