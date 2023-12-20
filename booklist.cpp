#include <iostream>
#include "booklist.h"
//������ ������ BookList//
BookList::~BookList() // ����������
{
    while (!setPtrsBook.empty()) // �������� ���� ����,
 {          // �������� ���������� �� ����������
        iter = setPtrsBook.begin();
        delete *iter;
        setPtrsBook.erase(iter);
    }
}
//---------------------------------------------------------


void BookList::insertBook(Book* ptrT)
{
    setPtrsBook.push_back(ptrT); // ������� ����� �����
}
//---------------------------------------------------------


void BookList::display()     // ����� ������ ����
{
    cout << "\nTitle\tAuthor\n-------------------\n";
    if (setPtrsBook.empty()) // ���� ������ ���� ����
  cout << "***List empty***\n" << endl; // ������� ������, ��� �� ����)
    else
    {
        iter = setPtrsBook.begin();
        while (iter != setPtrsBook.end())
        {
            cout << (*iter)->getTitle() << "    ||     " << (*iter)->getAuthor() << endl;
            *iter++;
        }
    }
}
//---------------------------------------------------------
