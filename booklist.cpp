#include <iostream>
#include "booklist.h"
//методы класса BookList//
BookList::~BookList() // деструктор
{
    while (!setPtrsBook.empty()) // удаление всех книг,
 {          // удаление указателей из контейнера
        iter = setPtrsBook.begin();
        delete *iter;
        setPtrsBook.erase(iter);
    }
}
//---------------------------------------------------------


void BookList::insertBook(Book* ptrT)
{
    setPtrsBook.push_back(ptrT); // вставка новой книги
}
//---------------------------------------------------------


void BookList::display()     // вывод списка книг
{
    cout << "\nTitle\tAuthor\n-------------------\n";
    if (setPtrsBook.empty()) // если список книг пуст
  cout << "***List empty***\n" << endl; // выводим запись, что он пуст)
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
