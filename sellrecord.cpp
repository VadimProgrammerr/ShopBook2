#include <iostream>
#include "sellrecord.h"
//������ ������ SellRecord//
SellRecord::~SellRecord() // ����������
{
    while (!setPtrsSR.empty())
    {
        iter = setPtrsSR.begin();
        delete *iter;
        setPtrsSR.erase(iter);
    }
}
//---------------------------------------------------------

void SellRecord::insertSell(string tTitle, int month, float amount) {
    iter = setPtrsSR.begin();       // ������������� ���������
    while (iter != setPtrsSR.end()) // ������� ������
    { 	// ���� ������� ������ ��������� � ��������� ��� ������,
        if (tTitle == (*iter)->gettTitle())
        {    // ������� ����� � ������
            (*iter)->setSell(month, amount);
            return;
        }
        else
            iter++;
    }   // ���� �� ����� ������ - ������� �����
    SellRow* ptrRow = new SellRow(tTitle);
    ptrRow->setSell(month, amount);     // ������� � ��� ������
    setPtrsSR.push_back(ptrRow);        // ������� ������ � ������
}
//---------------------------------------------------------

void SellRecord::display()  // ���������� ��� ������ � ��������
{
    cout << "\nTitle   Jan  Feb  Mar  Apr  May  Jun  Jul  Agu  Sep  Okt  Nov  Dec (rub)\n" << endl
        << "-------------------------------------------------------------------------------\n" << endl;
    if (setPtrsSR.empty())  	 	cout << "***List empty!***\n" << endl;
    else
    {
        iter = setPtrsSR.begin(); //�������� �� ������ � ����������� �� ������� SellRow
        while (iter != setPtrsSR.end())
        {
            cout << (*iter)->gettTitle() << '\t'; // ������� ��������
            for (int j = 0; j < 12; j++)                 // ������� 12 �������� ��������
                    {
                        if (((*iter)->getSellNo(j)) == 0)
                            cout << "  0  ";
                        else
                            cout << (*iter)->getSellNo(j) << "  ";
                    }
            cout << endl;
            iter++;
        }
        cout << endl;  	 	cout << endl;
    }
}
//---------------------------------------------------------


float SellRecord::getSumOfSells()  // ����� ���� ��������
{
    float sumSells = 0.0;
    iter = setPtrsSR.begin();
    while (iter != setPtrsSR.end())
    { 	// ������� ����� ���� ��������
        sumSells += (*iter)->getSumOfRow();
        iter++;
    }
    return sumSells;
}
//---------------------------------------------------------
