#include <iostream>
#include "expenserecord.h"
//������ ������ expenseRecord//
ExpenseRecord::~ExpenseRecord() // ����������
{ 	// ������� ������� expense
    // ������� ��������� �� ������
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

void ExpenseRecord::display() // ������������� ��� �������
{
    cout << "\nDate\tPoluchatel\tSumm\tCategory\n"
        << "----------------------------------------\n" << endl;
    if (vectPtrsExpenses.size() == 0) // � ���������� ��� ��������
        cout << "***List empty***\n" << endl;
    else
    {
        iter = vectPtrsExpenses.begin();
        while (iter != vectPtrsExpenses.end())
        {     // ������������� ��� �������
               cout << (*iter)->month << '/' << (*iter)->day << '\t' << (*iter)->payee << '\t' << '\t';
               cout << (*iter)->amount << '\t' << (*iter)->category << endl;
               iter++;
        }
        cout << endl;
    }
}
//--------------------------------------------------------

// ������������ ��� ����������� �������� ������
float ExpenseRecord::displaySummary()
{
    float totalExpenses = 0; // ����� �� ���� ���������� ��������

    if (vectPtrsExpenses.size() == 0)
    {
        cout << "\tAll category\t0\n";
        return 0;
    }

    iter = vectPtrsExpenses.begin();
    while (iter != vectPtrsExpenses.end())
    {
        //������� �� ����� ��������� ��������
        cout << '\t' << ((*iter)->category) << '\t' << ((*iter)->amount) << endl;
        totalExpenses += (*iter)->amount;  //������������ ��� �������
        iter++;
    }

    return totalExpenses;
}
//--------------------------------------------------------

