#include <iostream>
#include "bookinputscreen.h"
//����� ������ BookInputScreen//
void BookInputScreen::setBook() // �������� ������ � �����
{
    cout << "Title: " << endl;
    cin >> tTitle;
    cout << "Author: " << endl;
    cin >> tAuthor;
    cin.ignore(80, '\n');
    Book* ptrBook = new Book(tTitle, tAuthor);   // ������� �����
    ptrBookList->insertBook(ptrBook);            // ������� � ������ ����

}
//---------------------------------------------------------

