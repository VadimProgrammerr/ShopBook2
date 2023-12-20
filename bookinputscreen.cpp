#include <iostream>
#include "bookinputscreen.h"
//метод класса BookInputScreen//
void BookInputScreen::setBook() // добавить данные о книге
{
    cout << "Title: " << endl;
    cin >> tTitle;
    cout << "Author: " << endl;
    cin >> tAuthor;
    cin.ignore(80, '\n');
    Book* ptrBook = new Book(tTitle, tAuthor);   // создать книгу
    ptrBookList->insertBook(ptrBook);            // занести в список книг

}
//---------------------------------------------------------

