#ifndef EXPENSERECORD
#define EXPENSERECORD
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric>  //для accumulate()
#include "expense.h"
using namespace std;
//класс ExpenseRecord//
//Класс записей о затратах
class ExpenseRecord
{
private:
    vector<Expense*> vectPtrsExpenses; //вектор указателей на расходы
    vector<Expense*>::iterator iter;

public:
    ~ExpenseRecord();
    void insertExp(Expense*);
    void display();
    float displaySummary();  // нужно для годового отчета
};
#endif // EXPENSERECORD

