#include <iostream>
#include "sellrecord.h"
//методы класса SellRecord//
SellRecord::~SellRecord() // деструктор
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
    iter = setPtrsSR.begin();       // Инициализация итератора
    while (iter != setPtrsSR.end()) // условие выхода
    { 	// если текущий объект совпадает с созданным для поиска,
        if (tTitle == (*iter)->gettTitle())
        {    // заносим доход в список
            (*iter)->setSell(month, amount);
            return;
        }
        else
            iter++;
    }   // если не нашли строку - создаем новую
    SellRow* ptrRow = new SellRow(tTitle);
    ptrRow->setSell(month, amount);     // заносим в нее платеж
    setPtrsSR.push_back(ptrRow);        // заносим строку в вектор
}
//---------------------------------------------------------

void SellRecord::display()  // отобразить все строки с доходами
{
    cout << "\nTitle   Jan  Feb  Mar  Apr  May  Jun  Jul  Agu  Sep  Okt  Nov  Dec (rub)\n" << endl
        << "-------------------------------------------------------------------------------\n" << endl;
    if (setPtrsSR.empty())  	 	cout << "***List empty!***\n" << endl;
    else
    {
        iter = setPtrsSR.begin(); //итератор на список с указателями на объекты SellRow
        while (iter != setPtrsSR.end())
        {
            cout << (*iter)->gettTitle() << '\t'; // вывести название
            for (int j = 0; j < 12; j++)                 // вывести 12 арендных платежей
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


float SellRecord::getSumOfSells()  // сумма всех платежей
{
    float sumSells = 0.0;
    iter = setPtrsSR.begin();
    while (iter != setPtrsSR.end())
    { 	// плюсуем суммы всех платежей
        sumSells += (*iter)->getSumOfRow();
        iter++;
    }
    return sumSells;
}
//---------------------------------------------------------
