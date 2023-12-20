#ifndef BOOKLIST
#define BOOKLIST
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric>  //для accumulate()
#include "book.h"
using namespace std;
//класс BookList//
//класс BookList — список всех Книг.
//Он содержит множество указателей на класс Book
// и оперирует ими при выводе
class BookList
{
private:
    // установить указатели на книги
    list <Book*> setPtrsBook;  // указатели на класс книг
    list <Book*>::iterator iter; //итератор

public:
    ~BookList();            // деструктор (удаление книг)
    void insertBook(Book*); // добавить книгу в список
    string getTitle(string);// возвращает Название
    void display();         // вывод списка книг
};
#endif // BOOKLIST

