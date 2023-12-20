#ifndef EXPENSEINPUTSCREEN
#define EXPENSEINPUTSCREEN
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric>  //��� accumulate()
#include "expenserecord.h"
using namespace std;
//����� ExpenseInputScreen//
//����� ��� ����� ��������
class ExpenseInputScreen
{
private:
    ExpenseRecord* ptrExpenseRecord;  // ������ � ��������

public:
    ExpenseInputScreen(ExpenseRecord*);
    void setExpense();
};
#endif // EXPENSEINPUTSCREEN

