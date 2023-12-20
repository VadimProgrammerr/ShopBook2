#ifndef SELLROW
#define SELLROW
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric>  //��� accumulate()
using namespace std;
//����� SellRow//
//�����, �������� ���� ��������� ������ ������� (��������� ����)
// ���� ������ ������� �������: �������� � 12 �������� �����
class SellRow
{
private:
    string tTitle;        // �����, �� ������� ��������
    float Sell[12];       // ������

public:
    SellRow(string);                 // ����������� � ����� ����������
    void setSell(int, float);        // �������� ����� �� �����
    float getSumOfRow();             //����� �������� �� ����� ������ (����� � ����� �� ��� ������)
    string gettTitle();              //������ ��������
    float getSellNo(int);            //������ ������ �� ����� int
};
#endif // SELLROW

