#include <iostream>
#include "class.h"

char getaChar()                     // получение символа
{
    char ch = cin.get();
    cin.ignore(80, '\n');   //число пропускаемых символов и символ разделения
    return ch;
}
//---------------------------------------------------------

//методы класса userInterface//
UserInterface::UserInterface()
{

}
//---------------------------------------------------------

UserInterface::~UserInterface()
{

}
//---------------------------------------------------------

void UserInterface::interact()
{
    while (true)
    {
        cout << "1.Для добавления данных\n" <<  "2.Для вывода отчета\n"  <<  "3.Для выхода\n";
        ch = getaChar();
        if (ch == '1') // ввод данных
        {
            cout << "1.Нажмите для добавления Книги\n"  << "2.Для записи оплаты\n" <<  "3.Для записи расходов\n";
            ch = getaChar();
            switch (ch)
            {
            case '1':
                cout << "В разработке" << endl;
                break;
            case '2':
                cout << "В разработке" << endl;
                break;
            case '3':
                cout << "В разработке" << endl;
                break;
            default: cout << "Неизвестная функция\n";
                break;
            }                   // конец секции switch
        }                       // конец условия if
        else if (ch == '2')     // вывод данных
        {
            cout << "1.Нажмите для вывода списка книг\n"
                    <<  "2.Для вывода статистики продаж\n"
                    <<  "3.Для вывода расходов\n"
                    <<  "4.Для вывода годового отчета\n";
            ch = getaChar();
            switch (ch)
            {
            case '1':
                cout << "В разработке" << endl;
            case '2':
                cout << "В разработке" << endl;
            case '3':
                cout << "В разработке" << endl;
            case '4':
                cout << "В разработке" << endl;

                    break;
            default: cout << "Неизвестная функция вывода\n";
                    break;
            }                 // конец switch
        }                     // конец elseif
        else if (ch == '3')
            return;           // выход
        else
            cout << "Неизвестная функция";
    }                         // конец while
}
