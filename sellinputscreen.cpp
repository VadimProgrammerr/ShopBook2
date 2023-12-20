#include <iostream>
#include "sellinputscreen.h"
//методы класса SellInputScreen//
void SellInputScreen::setSell()
{
    cout << "Title: ";
    cin >> SoldBook;
    cout << "Number of money: " << endl;
    cin >> SellPaid;       // вводим оплату
    cin.ignore(80, '\n');
    cout << "Enter month (1-12): " << endl;
    cin >> month;
    cin.ignore(80, '\n');
    month--;                  // (внутренняя нумерация 0-11)
    // вставляем доход в запись об оплате
    ptrSellRecord->insertSell(SoldBook, month, SellPaid);

}
//---------------------------------------------------------
