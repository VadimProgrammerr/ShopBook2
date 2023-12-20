#ifndef EXPENSE
#define EXPENSE
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric>  //��� accumulate()
using namespace std;
//����� Expense//
//����� ������
class Expense
{
public:
    int month, day;  // ����� � ���� ������ ��������
    string category; // ��������� �������� (�����, ����, ������ � ��)
    string payee;    // ���� ������ (���������� ����, �����, ������)
    float amount;    // ������� ������
    Expense()
    {  }
    Expense(int m, int d, string c, string p, float a) :
        month(m), day(d), category(c), payee(p), amount(a)
    {

    }
};
#endif // EXPENSE

