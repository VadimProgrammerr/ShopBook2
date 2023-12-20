#ifndef BOOKLIST
#define BOOKLIST
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric>  //��� accumulate()
#include "book.h"
using namespace std;
//����� BookList//
//����� BookList � ������ ���� ����.
//�� �������� ��������� ���������� �� ����� Book
// � ��������� ��� ��� ������
class BookList
{
private:
    // ���������� ��������� �� �����
    list <Book*> setPtrsBook;  // ��������� �� ����� ����
    list <Book*>::iterator iter; //��������

public:
    ~BookList();            // ���������� (�������� ����)
    void insertBook(Book*); // �������� ����� � ������
    string getTitle(string);// ���������� ��������
    void display();         // ����� ������ ����
};
#endif // BOOKLIST

