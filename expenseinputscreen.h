#ifndef EXPENSEINPUTSCREEN
#define EXPENSEINPUTSCREEN
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric>  //для accumulate()
#include "expenserecord.h"
using namespace std;
//класс ExpenseInputScreen//
//Класс для ввода расходов
class ExpenseInputScreen
{
private:
    ExpenseRecord* ptrExpenseRecord;  // запись о расходах

public:
    ExpenseInputScreen(ExpenseRecord*);
    void setExpense();
};
#endif // EXPENSEINPUTSCREEN

