#ifndef SELLRECORD
#define SELLRECORD
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric>  //��� accumulate()
#include "sellrow.h"
using namespace std;
// ����� SellRecord //
//����� SellRecord. �� ������ ��������������� ������ �� �������.
//� ��� ����� ����������������� ����� ���������� ������.
class SellRecord
{
private:
    list <SellRow*> setPtrsSR; // ��������� �� ������� SellRow (�� ������ �� �����)
    list <SellRow*>::iterator iter;
 public:
    ~SellRecord();
    void insertSell(string, int, float);    // �������� �����
    void display();                         // ���������� ��� ������ � ��������
    float getSumOfSells();                  // ���������� ����� ������� �� ���� ����
};
#endif // SELLRECORD

