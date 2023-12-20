#ifndef EXPENSE
#define EXPENSE
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric>  //дл€ accumulate()
using namespace std;
//класс Expense//
// ласс затрат
class Expense
{
public:
    int month, day;  // мес€ц и день уплаты расходов
    string category; // категори€ расходов (книги, свет, ремонт и тд)
    string payee;    // кому платим (поставщики книг, света, аренда)
    float amount;    // сколько платим
    Expense()
    {  }
    Expense(int m, int d, string c, string p, float a) :
        month(m), day(d), category(c), payee(p), amount(a)
    {

    }
};
#endif // EXPENSE

