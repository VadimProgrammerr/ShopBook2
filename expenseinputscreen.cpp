#include <iostream>
#include "expenseinputscreen.h"
#include "globals.h"
//������ ������ ExpenseInputScreen//
// �����������
ExpenseInputScreen::ExpenseInputScreen(ExpenseRecord* per) : ptrExpenseRecord(per)
{

}
//------------------------------------------------------

void ExpenseInputScreen::setExpense()
{
    int month, day;
    string category, payee;
    float amount;

    cout << "Enter month (1-12): ";
    cin >> month;
    cin.ignore(80, '\n');
    cout << "Enter day (1-31): ";
    cin >> day;
    cin.ignore(80, '\n');
    cout << "Enter category: ";
    getaLine(category);
    cout << "Enter poluchatel: ";
    getaLine(payee);
    cout << "Enter summ: ";
    cin >> amount;
    cin.ignore(80, '\n');
    // ������� ����� ������
    Expense* ptrExpense = new Expense(month, day, category, payee, amount);
    // ��������� ������ � ������ ���� ��������
    ptrExpenseRecord->insertExp(ptrExpense);
}
//---------------------------------------------------------

