#include <iostream>
#include "sellinputscreen.h"
//������ ������ SellInputScreen//
void SellInputScreen::setSell()
{
    cout << "Title: ";
    cin >> SoldBook;
    cout << "Number of money: " << endl;
    cin >> SellPaid;       // ������ ������
    cin.ignore(80, '\n');
    cout << "Enter month (1-12): " << endl;
    cin >> month;
    cin.ignore(80, '\n');
    month--;                  // (���������� ��������� 0-11)
    // ��������� ����� � ������ �� ������
    ptrSellRecord->insertSell(SoldBook, month, SellPaid);

}
//---------------------------------------------------------
