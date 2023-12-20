#include <iostream>
#include "expenserecord.h"
//методы класса expenseRecord//
ExpenseRecord::~ExpenseRecord() // деструктор
{ 	// удалить объекты expense
    // удалить указатели на вектор
    while (!vectPtrsExpenses.empty())
    {
        iter = vectPtrsExpenses.begin();
        delete *iter;
        vectPtrsExpenses.erase(iter);
    }
}
//--------------------------------------------------------

void ExpenseRecord::insertExp(Expense* ptrExp) {
vectPtrsExpenses.push_back(ptrExp);
}
//---------------------------------------------------------

void ExpenseRecord::display() // распечатываем все расходы
{
    cout << "\nDate\tPoluchatel\tSumm\tCategory\n"
        << "----------------------------------------\n" << endl;
    if (vectPtrsExpenses.size() == 0) // ¬ контейнере нет расходов
        cout << "***List empty***\n" << endl;
    else
    {
        iter = vectPtrsExpenses.begin();
        while (iter != vectPtrsExpenses.end())
        {     // распечатываем все расходы
               cout << (*iter)->month << '/' << (*iter)->day << '\t' << (*iter)->payee << '\t' << '\t';
               cout << (*iter)->amount << '\t' << (*iter)->category << endl;
               iter++;
        }
        cout << endl;
    }
}
//--------------------------------------------------------

// используетс€ при составлении годового отчета
float ExpenseRecord::displaySummary()
{
    float totalExpenses = 0; // —умма по всем категори€м расходов

    if (vectPtrsExpenses.size() == 0)
    {
        cout << "\tAll category\t0\n";
        return 0;
    }

    iter = vectPtrsExpenses.begin();
    while (iter != vectPtrsExpenses.end())
    {
        //выводим на экран категории расходов
        cout << '\t' << ((*iter)->category) << '\t' << ((*iter)->amount) << endl;
        totalExpenses += (*iter)->amount;  //подсчитываем все расходы
        iter++;
    }

    return totalExpenses;
}
//--------------------------------------------------------

