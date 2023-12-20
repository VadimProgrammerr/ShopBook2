#ifndef SELLROW
#define SELLROW
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric>  //для accumulate()
using namespace std;
//класс SellRow//
//класс, хранящий одну табличную строку доходов (купленных книг)
// одна строка таблицы прибыли: название и 12 месячных оплат
class SellRow
{
private:
    string tTitle;        // книга, за которые уплачено
    float Sell[12];       // месяцы

public:
    SellRow(string);                 // конструктор с одним параметром
    void setSell(int, float);        // добавить доход за месяц
    float getSumOfRow();             //сумма платежей из одной строки (доход с книги за все месяцы)
    string gettTitle();              //Запрос названия
    float getSellNo(int);            //Запрос дохода за месяц int
};
#endif // SELLROW

