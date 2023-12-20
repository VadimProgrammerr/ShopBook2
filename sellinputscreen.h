#ifndef SELLINPUTSCREEN
#define SELLINPUTSCREEN
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric>  //для accumulate()
#include "booklist.h"
#include "sellrecord.h"
using namespace std;
//класс  SellInputScreen //
//Экран для добавления продажи
class SellInputScreen
{
private:
    BookList* ptrBookList;          // список книг
    SellRecord* ptrSellRecord;      // список записей об оплате
    string SoldBook;                // название проданной книги
    float SellPaid;                 // оплата
    int month;                      // за месяц
public:
    SellInputScreen(BookList* ptrTL, SellRecord* ptrRR) : ptrBookList(ptrTL), ptrSellRecord(ptrRR)
    {

    }
    void setSell();  // добавить плату одного покупателя за месяц
};
#endif // SELLINPUTSCREEN

