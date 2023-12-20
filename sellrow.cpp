#include <iostream>
#include "sellrow.h"
//������ ������ SellRow//
SellRow::SellRow(string an) : tTitle(an) //�����������
{
    //�������� fill() �������� ����� �������� value (� ��� ��� 0)
    //� ������ ������� ���������, ������������� ����� ���������� [first,last).
    //�.�. � ������������ ������ �������������� ������ ���������� 0.
    fill(&Sell[0], &Sell[12], 0);
}
//---------------------------------------------------------

void SellRow::setSell(int m, float am) // ������ ������ �� ����� m, ����� - am
{
    Sell[m] = am;   // ����������� ������ � ������
}
//---------------------------------------------------------

string SellRow::gettTitle() // ������ ������ ��������
{
    return tTitle;
}
//---------------------------------------------------------

float SellRow::getSellNo(int month) //������ ������ ������ �� ����� month
{
    return Sell[month];
}
//---------------------------------------------------------

float SellRow::getSumOfRow() // c���� ������� � ������
{
    //�� ��������� �������� accumulate() ��������� ��������.
    //����� ������� ����� ������, �������� ����� � �������� �� �������� �������� ����������.
    //���� ����� ��� ����, �� ����� ���� � ��������� ������ ����������.
    return accumulate(&Sell[0], &Sell[12], 0);
}
//---------------------------------------------------------
