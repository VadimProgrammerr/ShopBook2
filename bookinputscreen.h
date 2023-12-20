#ifndef BOOKINPUTSCREEN
#define BOOKINPUTSCREEN
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric>  //для accumulate()
#include "booklist.h"
using namespace std;
//класс BookInputScreen//
//класс BookInputScreen. Это класс, отвечающий за отображение «экрана»,
//куда пользователь может ввести данные о новой книги:
class BookInputScreen
{
private:
    BookList* ptrBookList;
    string tTitle;
    string tAuthor;

public:
    BookInputScreen(BookList* ptrTL) : ptrBookList(ptrTL)
    {

    }
    void setBook(); // добавить данные о книге
};
#endif // BOOKINPUTSCREEN

