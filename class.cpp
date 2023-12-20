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
    cout << "Title: " << endl;
    cin >> tTitle;
    cout << "Author: " << endl;
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
    cout << "\nTitle\tAuthor\n-------------------\n";
    if (setPtrsBook.empty()) // ���� ������ ���� ����
  cout << "***List empty***\n" << endl; // ������� ������, ��� �� ����)
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

//������ ������ SellInputScreen//
void SellInputScreen::setSell()
{
    cout << "Title: ";
    cin >> SoldBook;
    cout << "Number of money: " << endl;
    cin >> SellPaid;       // ������ ������
    cin.ignore(80, '\n');
    cout << "Enter month (1-12): " << endl;
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
    cout << "\nDate\tPoluchatel\tSumm\tCategory\n"
        << "----------------------------------------\n" << endl;
    if (vectPtrsExpenses.size() == 0) // � ���������� ��� ��������
        cout << "***List empty***\n" << endl;
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
        cout << "\tAll category\t0\n";
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

//������ ������ ExpenseInputScreen//
// �����������
ExpenseInputScreen::ExpenseInputScreen(ExpenseRecord* per) : ptrExpenseRecord(per)
{

}
//------------------------------------------------------

void ExpenseInputScreen::setExpense()
{
    int month, day;
    string category, payee;
    float amount;

    cout << "Enter month (1-12): ";
    cin >> month;
    cin.ignore(80, '\n');
    cout << "Enter day (1-31): ";
    cin >> day;
    cin.ignore(80, '\n');
    cout << "Enter category: ";
    getaLine(category);
    cout << "Enter poluchatel: ";
    getaLine(payee);
    cout << "Enter summ: ";
    cin >> amount;
    cin.ignore(80, '\n');
    // ������� ����� ������
    Expense* ptrExpense = new Expense(month, day, category, payee, amount);
    // ��������� ������ � ������ ���� ��������
    ptrExpenseRecord->insertExp(ptrExpense);
}
//---------------------------------------------------------

//������ ������ AnnualReport//
//�����������
AnnualReport::AnnualReport(SellRecord* pSR, ExpenseRecord* pER) : ptrRR(pSR), ptrER(pER) {

}
//---------------------------------------------------------


void AnnualReport::display()
 {
        cout << "Year report\n--------------\n" << endl;
        cout << "Incomes\n" << endl;
        cout << "\tIncomes from selling books: ";
        Sells = ptrRR->getSumOfSells();
        cout << Sells << endl;
        cout << "Outcomes\n" << endl;
        expenses = ptrER->displaySummary();
        cout << "Total outcomes: ";
        cout << expenses << endl;  	 	// ��������� ������������
        cout << "\nBalance: " << (Sells - expenses) << endl;
}
//---------------------------------------------------------


//������ ������ userInterface//
UserInterface::UserInterface()
{
    ptrBookList = new BookList;
    ptrSellRecord = new SellRecord;
    ptrExpenseRecord = new ExpenseRecord;
}
//---------------------------------------------------------

UserInterface::~UserInterface()
{
    delete ptrBookList;
    delete ptrSellRecord;
    delete ptrExpenseRecord;
}
//---------------------------------------------------------

void UserInterface::interact()
{
    while (true)
    {
        cout << "1.Enter data\n" <<  "2.Report out\n"  <<  "3.Exit\n";
        ch = getaChar();
        if (ch == '1') // ���� ������
        {
            cout << "1.Add book\n"  << "2.Add incomes\n" <<  "3.Add outcomes\n";
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
            case '3': ptrExpenseInputScreen =
                        new ExpenseInputScreen(ptrExpenseRecord);
                ptrExpenseInputScreen->setExpense();
                delete ptrExpenseInputScreen;
                break;
            default: cout << "Error\n";
                break;
            }                   // ����� ������ switch
        }                       // ����� ������� if
        else if (ch == '2')     // ����� ������
        {
            cout << "1.Show books\n"
                    <<  "2.Show incomes\n"
                    <<  "3.Show outcomes\n"
                    <<  "4.Show year record\n";
            ch = getaChar();
            switch (ch)
            {
            case '1': ptrBookList->display();
                    break;
            case '2': ptrSellRecord->display();
                    break;
            case '3': ptrExpenseRecord->display();
                    break;
            case '4': ptrAnnualReport = new AnnualReport(ptrSellRecord,ptrExpenseRecord);
                    ptrAnnualReport->display();
                    delete ptrAnnualReport;
                    break;
            default: cout << "Error\n";
                    break;
            }                 // ����� switch
        }                     // ����� elseif
        else if (ch == '3')
            return;           // �����
        else
            cout << "Error";
    }                         // ����� while
}                             // ����� interact()

