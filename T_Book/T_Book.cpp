#include <iostream>
#include "Abonent.h"
#include "FileBook.h"
#include <Windows.h>
using namespace std;

int Count();

int main()
{
    setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int count = Count();
	int ch = NULL;
	char fio[30];
	int index = NULL;
	FileBook fb{ (char*)"Tellbook.txt" };
	Abonent* book = fb.LoadBookFile();
	do
	{
		system("cls");
		cout << "1. Добавить абонента\n"
			<< "2. Удалить абонента\n"
			<< "3. Поиск по фио\n"
			<< "4. Сохранить изминения\n"
			<< "5. Показать сотрудников\n"
			<< "0. Выход\n";

		cin >> ch;
		switch (ch)
		{
		case 1:
			book->Add(book, &count);
			break;
		case 2:
			printf("Введите индекс сотрудника, которого нужно удалить: ");
			scanf_s("%d", &index);
			book->deleteAbonent(book, &count, index);
			break;
		case 3:
			printf("Введите фамилию сотрудника для поиска: ");
			scanf_s("%s", fio, sizeof(fio));
			book->findFIO(book, count, fio);
			system("pause");
			break;
		case 4:
			fb.SaveBookFile(book, count);
			break;
		case 5:
			book->Print(book, count);
			system("pause");
			break;
		default:
			break;
		}
	} while (ch != 0);


}

int Count() {
	FILE* file;
	int count = 0;
	char* s = new char[100];
	if (!fopen_s(&file, "Tellbook.txt", READ)) {
		while (!feof(file)) {
			fgets(s, 100, file);
			count++;
		}
	}
	fclose(file);
	return count;
}