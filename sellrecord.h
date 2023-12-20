#ifndef SELLRECORD
#define SELLRECORD
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric>  //дл€ accumulate()
#include "sellrow.h"
using namespace std;
// класс SellRecord //
//класс SellRecord. ќн хранит непосредственно записи об продаже.
//— ним будет взаимодействовать экран добавлени€ дохода.
class SellRecord
{
private:
    list <SellRow*> setPtrsSR; // указатели на объекты SellRow (по одному на книгу)
    list <SellRow*>::iterator iter;
 public:
    ~SellRecord();
    void insertSell(string, int, float);    // добавить доход
    void display();                         // отобразить все строки с доходами
    float getSumOfSells();                  // подсчитать сумму доходов от всех книг
};
#endif // SELLRECORD

