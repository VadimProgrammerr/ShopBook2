#include <iostream>
#include "class.h"

void getaLine(string& inStr) // ��������� ������ ������
{
    char temp[21];
    cin.get(temp, 20, '\n');
    cin.ignore(20, '\n');     //����� ������������ �������� � ������ ����������
    inStr = temp;
}
//---------------------------------------------------------

char getaChar()                     // ��������� �������
{
    char ch = cin.get();
    cin.ignore(80, '\n');   //����� ������������ �������� � ������ ����������
    return ch;
}
//---------------------------------------------------------

//������ ������ Book//
//� ������������ ����� �������� � ������
Book::Book(string n, string Au) : Title(n), Author(Au)
{

}
//---------------------------------------------------------

Book::~Book() // ����������
{

}
//---------------------------------------------------------

string Book::getAuthor() //������ ���������� ��������
{
    return Author;
}
//--------------------------------------------------------

string Book::getTitle() //������ ���������� ������
{
    return Title;
}
//---------------------------------------------------------

//����� ������ BookInputScreen//
void BookInputScreen::setBook() // �������� ������ � �����
{
    cout << "������� ��������: " << endl;
    cin >> tTitle;
    cout << "������� ������: " << endl;
    cin >> tAuthor;
    cin.ignore(80, '\n');
    Book* ptrBook = new Book(tTitle, tAuthor);   // ������� �����
    ptrBookList->insertBook(ptrBook);            // ������� � ������ ����

}
//---------------------------------------------------------

//������ ������ BookList//
BookList::~BookList() // ����������
{
    while (!setPtrsBook.empty()) // �������� ���� ����,
 {          // �������� ���������� �� ����������
        iter = setPtrsBook.begin();
        delete *iter;
        setPtrsBook.erase(iter);
    }
}
//---------------------------------------------------------


void BookList::insertBook(Book* ptrT)
{
    setPtrsBook.push_back(ptrT); // ������� ����� �����
}
//---------------------------------------------------------


void BookList::display()     // ����� ������ ����
{
    cout << "\n��������\t�����\n-------------------\n";
    if (setPtrsBook.empty()) // ���� ������ ���� ����
  cout << "***��� �������***\n" << endl; // ������� ������, ��� �� ����)
    else
    {
        iter = setPtrsBook.begin();
        while (iter != setPtrsBook.end())
        {
            cout << (*iter)->getTitle() << "    ||     " << (*iter)->getAuthor() << endl;
            *iter++;
        }
    }
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
            case '1': ptrBookInputScreen =
                        new BookInputScreen(ptrBookList);
                ptrBookInputScreen->setBook();
                delete ptrBookInputScreen;
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
