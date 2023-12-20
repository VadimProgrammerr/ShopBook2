#ifndef EXPENSERECORD
#define EXPENSERECORD
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric>  //��� accumulate()
#include "expense.h"
using namespace std;
//����� ExpenseRecord//
//����� ������� � ��������
class ExpenseRecord
{
private:
    vector<Expense*> vectPtrsExpenses; //������ ���������� �� �������
    vector<Expense*>::iterator iter;

public:
    ~ExpenseRecord();
    void insertExp(Expense*);
    void display();
    float displaySummary();  // ����� ��� �������� ������
};
#endif // EXPENSERECORD

