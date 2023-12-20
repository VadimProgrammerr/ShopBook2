#include <iostream>
#include "userinterface.h"
#include "globals.h"
//методы класса userInterface//
UserInterface::UserInterface()
{
    ptrBookList = new BookList;
    ptrSellRecord = new SellRecord;
    ptrExpenseRecord = new ExpenseRecord;
}
//---------------------------------------------------------

UserInterface::~UserInterface()
{
    delete ptrBookList;
    delete ptrSellRecord;
    delete ptrExpenseRecord;
}
//---------------------------------------------------------

void UserInterface::interact()
{
    while (true)
    {
        cout << "1.Enter data\n" <<  "2.Report out\n"  <<  "3.Exit\n";
        ch = getaChar();
        if (ch == '1') // ввод данных
        {
            cout << "1.Add book\n"  << "2.Add incomes\n" <<  "3.Add outcomes\n";
            ch = getaChar();
            switch (ch)
            {
            case '1': ptrBookInputScreen =
                        new BookInputScreen(ptrBookList);
                ptrBookInputScreen->setBook();
                delete ptrBookInputScreen;
                break;
            case '2': ptrSellInputScreen =
                        new SellInputScreen(ptrBookList, ptrSellRecord);
                ptrSellInputScreen->setSell();
                delete ptrSellInputScreen;
                break;
            case '3': ptrExpenseInputScreen =
                        new ExpenseInputScreen(ptrExpenseRecord);
                ptrExpenseInputScreen->setExpense();
                delete ptrExpenseInputScreen;
                break;
            default: cout << "Error\n";
                break;
            }                   // конец секции switch
        }                       // конец условия if
        else if (ch == '2')     // вывод данных
        {
            cout << "1.Show books\n"
                    <<  "2.Show incomes\n"
                    <<  "3.Show outcomes\n"
                    <<  "4.Show year record\n";
            ch = getaChar();
            switch (ch)
            {
            case '1': ptrBookList->display();
                    break;
            case '2': ptrSellRecord->display();
                    break;
            case '3': ptrExpenseRecord->display();
                    break;
            case '4': ptrAnnualReport = new AnnualReport(ptrSellRecord,ptrExpenseRecord);
                    ptrAnnualReport->display();
                    delete ptrAnnualReport;
                    break;
            default: cout << "Error\n";
                    break;
            }                 // конец switch
        }                     // конец elseif
        else if (ch == '3')
            return;           // выход
        else
            cout << "Error";
    }                         // конец while
}                             // конец interact()

