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
    cout << "\n��������   ���  ���  ���  ���  ���  ��� ���  ���  ���  ���  ���  ��� �����,���\n" << endl
        << "-------------------------------------------------------------------------------\n" << endl;
    if (setPtrsSR.empty())  	 	cout << "***��� �������!***\n" << endl;
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

//������ ������ SellInputScreen//
void SellInputScreen::setSell()
{
    cout << "��������: ";
    cin >> SoldBook;
    cout << "������� ����� �������: " << endl;
    cin >> SellPaid;       // ������ ������
    cin.ignore(80, '\n');
    cout << "������� ����� ������ ������ (1-12): " << endl;
    cin >> month;
    cin.ignore(80, '\n');
    month--;                  // (���������� ��������� 0-11)
    // ��������� ����� � ������ �� ������
    ptrSellRecord->insertSell(SoldBook, month, SellPaid);

}
//---------------------------------------------------------

//������ ������ expenseRecord//
ExpenseRecord::~ExpenseRecord() // ����������
{ 	// ������� ������� expense
    // ������� ��������� �� ������
    while (!vectPtrsExpenses.empty())
    {
        iter = vectPtrsExpenses.begin();
        delete *iter;
        vectPtrsExpenses.erase(iter);
    }
}
//--------------------------------------------------------

void ExpenseRecord::insertExp(Expense* ptrExp) {
vectPtrsExpenses.push_back(ptrExp);
}
//---------------------------------------------------------

void ExpenseRecord::display() // ������������� ��� �������
{
    cout << "\n����\t����������\t�����\t���������\n"
        << "----------------------------------------\n" << endl;
    if (vectPtrsExpenses.size() == 0) // � ���������� ��� ��������
        cout << "***�������� ���***\n" << endl;
    else
    {
        iter = vectPtrsExpenses.begin();
        while (iter != vectPtrsExpenses.end())
        {     // ������������� ��� �������
               cout << (*iter)->month << '/' << (*iter)->day << '\t' << (*iter)->payee << '\t' << '\t';
               cout << (*iter)->amount << '\t' << (*iter)->category << endl;
               iter++;
        }
        cout << endl;
    }
}
//--------------------------------------------------------

// ������������ ��� ����������� �������� ������
float ExpenseRecord::displaySummary()
{
    float totalExpenses = 0; // ����� �� ���� ���������� ��������

    if (vectPtrsExpenses.size() == 0)
    {
        cout << "\t��� ���������\t0\n";
        return 0;
    }

    iter = vectPtrsExpenses.begin();
    while (iter != vectPtrsExpenses.end())
    {
        //������� �� ����� ��������� ��������
        cout << '\t' << ((*iter)->category) << '\t' << ((*iter)->amount) << endl;
        totalExpenses += (*iter)->amount;  //������������ ��� �������
        iter++;
    }

    return totalExpenses;
}
//--------------------------------------------------------


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
            case '2': ptrSellInputScreen =
                        new SellInputScreen(ptrBookList, ptrSellRecord);
                ptrSellInputScreen->setSell();
                delete ptrSellInputScreen;
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
            case '1': ptrBookList->display();
                break;
            case '2': ptrSellRecord->display();
                break;
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
