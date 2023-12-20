#include <iostream>
#include "annualReport.h"
//������ ������ AnnualReport//
//�����������
AnnualReport::AnnualReport(SellRecord* pSR, ExpenseRecord* pER) : ptrRR(pSR), ptrER(pER) {

}
//---------------------------------------------------------


void AnnualReport::display()
 {
        cout << "Year report\n--------------\n" << endl;
        cout << "Incomes\n" << endl;
        cout << "\tIncomes from selling books: ";
        Sells = ptrRR->getSumOfSells();
        cout << Sells << endl;
        cout << "Outcomes\n" << endl;
        expenses = ptrER->displaySummary();
        cout << "Total outcomes: ";
        cout << expenses << endl;  	 	// ��������� ������������
        cout << "\nBalance: " << (Sells - expenses) << endl;
}
//---------------------------------------------------------

