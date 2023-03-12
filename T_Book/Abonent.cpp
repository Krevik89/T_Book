#include "Abonent.h"

void Abonent::Print(Abonent book[], int s) {
    cout << "   FIO \t\t" << "  �������� \t" << "  ������� \t" << "  ��������� \t" << "  ���� \t\n";
    for (int i = 0; i < s; i++) {
        cout << i + 1 << " " << book[i]._FIO
            << " \t| " << book[i]._h_phone
            << " \t| " << book[i]._w_phone
            << " \t| " << book[i]._m_phone
            << " \t| " << book[i]._add_info
            << endl;
    }
}

void Abonent::findFIO(Abonent book[], int count, char* fio) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(book[i]._FIO, fio) == 0) {
            book->Print(book, count);
            found = 1;
        }
    }
    if (!found) {
        printf("��������� � �������� %s �� ������!\n\n", fio);
    }
}

void Abonent::deleteAbonent(Abonent book[], int* s, int index) {
    if (index >= 0 && index < *s) {
        char fio[30];
        // �������� ��� �������� ������� �� ���� ������� �����
        for (int i = index; i < *s - 1; i++) {
            strcpy_s(fio, 30, book[i]._FIO);
            strcpy_s(book[i+1]._FIO,30, fio);
            book[i]._h_phone = book[i + 1]._h_phone;
            book[i]._w_phone = book[i + 1]._w_phone;
            book[i]._m_phone = book[i + 1]._m_phone;
            strcpy_s(book[i]._add_info, book[i + 1]._add_info);
        }
        // ��������� ���������� ����������� �� 1
        (*s)--;
        printf("��������� ������� ������!\n\n");
    }
    else {
        printf("������������ ������ ����������!\n\n");
    }
}

void Abonent::Add(Abonent book[], int* s) {
    Abonent newabonet;
    char fio2[30];
    printf("������� ��� ");
    scanf_s("%s", fio2,sizeof(fio2));
    strcpy_s(newabonet._FIO, 30,fio2);
    printf("������� �������� ");
    cin>>newabonet._h_phone;
    printf("������� ������� ");
    cin>>newabonet._w_phone;
    printf("������� ��������� ");
    cin>>newabonet._m_phone;
    printf("������� ��� ���������� ");
    scanf_s("%s", newabonet._add_info, sizeof(newabonet._add_info));
    book[*s] = newabonet;
    (*s)++;
    printf("��������� ������� ��������!\n");
}