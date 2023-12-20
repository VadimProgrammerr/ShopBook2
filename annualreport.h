#ifndef ANNUALREPORT
#define ANNUALREPORT
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric>  //для accumulate()
#include "sellrecord.h"
#include "expenserecord.h"
using namespace std;
//класс AnnualReport//
//Класс годового отчета
class AnnualReport
{
private:
    SellRecord* ptrRR;     // записи доходов
    ExpenseRecord* ptrER;  // записи расходов
    float expenses, Sells; // суммы доходов и расходов

public:
    AnnualReport(SellRecord*, ExpenseRecord*);
    void display();  // отображение годового отчета
};
#endif // ANNUALREPORT

