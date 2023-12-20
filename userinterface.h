#ifndef USERINTERFACE
#define USERINTERFACE
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric>  //��� accumulate()
#include "booklist.h"
#include "bookinputscreen.h"
#include "sellrecord.h"
#include "sellinputscreen.h"
#include "expenserecord.h"
#include "expenseinputscreen.h"
#include "annualreport.h"
using namespace std;
//����� UserInterface//
//������� ����� ��� ������� ����������:
//���� ����� ���������� �������������� ����� � ����������.
class UserInterface
{
private:
    BookList*            ptrBookList;
    BookInputScreen*     ptrBookInputScreen;
    SellRecord*          ptrSellRecord;
    SellInputScreen*     ptrSellInputScreen;
    ExpenseRecord*       ptrExpenseRecord;
    ExpenseInputScreen*  ptrExpenseInputScreen;
    AnnualReport*        ptrAnnualReport;
    char ch;

public:
    UserInterface();
    ~UserInterface();
    void interact();
};

#endif // USERINTERFACE

