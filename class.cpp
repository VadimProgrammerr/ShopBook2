#include <iostream>
#include "class.h"

char getaChar()                     // ��������� �������
{
    char ch = cin.get();
    cin.ignore(80, '\n');   //����� ������������ �������� � ������ ����������
    return ch;
}
//---------------------------------------------------------

//������ ������ userInterface//
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
        cout << "1.��� ���������� ������\n" <<  "2.��� ������ ������\n"  <<  "3.��� ������\n";
        ch = getaChar();
        if (ch == '1') // ���� ������
        {
            cout << "1.������� ��� ���������� �����\n"  << "2.��� ������ ������\n" <<  "3.��� ������ ��������\n";
            ch = getaChar();
            switch (ch)
            {
            case '1':
                cout << "� ����������" << endl;
                break;
            case '2':
                cout << "� ����������" << endl;
                break;
            case '3':
                cout << "� ����������" << endl;
                break;
            default: cout << "����������� �������\n";
                break;
            }                   // ����� ������ switch
        }                       // ����� ������� if
        else if (ch == '2')     // ����� ������
        {
            cout << "1.������� ��� ������ ������ ����\n"
                    <<  "2.��� ������ ���������� ������\n"
                    <<  "3.��� ������ ��������\n"
                    <<  "4.��� ������ �������� ������\n";
            ch = getaChar();
            switch (ch)
            {
            case '1':
                cout << "� ����������" << endl;
            case '2':
                cout << "� ����������" << endl;
            case '3':
                cout << "� ����������" << endl;
            case '4':
                cout << "� ����������" << endl;

                    break;
            default: cout << "����������� ������� ������\n";
                    break;
            }                 // ����� switch
        }                     // ����� elseif
        else if (ch == '3')
            return;           // �����
        else
            cout << "����������� �������";
    }                         // ����� while
}
