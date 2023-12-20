#ifndef ANNUALREPORT
#define ANNUALREPORT
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric>  //��� accumulate()
#include "sellrecord.h"
#include "expenserecord.h"
using namespace std;
//����� AnnualReport//
//����� �������� ������
class AnnualReport
{
private:
    SellRecord* ptrRR;     // ������ �������
    ExpenseRecord* ptrER;  // ������ ��������
    float expenses, Sells; // ����� ������� � ��������

public:
    AnnualReport(SellRecord*, ExpenseRecord*);
    void display();  // ����������� �������� ������
};
#endif // ANNUALREPORT

