#ifndef SELLINPUTSCREEN
#define SELLINPUTSCREEN
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric>  //��� accumulate()
#include "booklist.h"
#include "sellrecord.h"
using namespace std;
//�����  SellInputScreen //
//����� ��� ���������� �������
class SellInputScreen
{
private:
    BookList* ptrBookList;          // ������ ����
    SellRecord* ptrSellRecord;      // ������ ������� �� ������
    string SoldBook;                // �������� ��������� �����
    float SellPaid;                 // ������
    int month;                      // �� �����
public:
    SellInputScreen(BookList* ptrTL, SellRecord* ptrRR) : ptrBookList(ptrTL), ptrSellRecord(ptrRR)
    {

    }
    void setSell();  // �������� ����� ������ ���������� �� �����
};
#endif // SELLINPUTSCREEN

