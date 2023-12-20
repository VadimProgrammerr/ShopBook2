#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric>  //��� accumulate()
using namespace std;

// ���������� ������ //
void getaLine(string& inStr);  // ��������� ������ ������
char getaChar();  // ��������� �������

// ����� Book (�����) //
//�� ������ �������� � ������ �����, ������� � ��� ����.
class Book
{
private:
    string Title;  // ��������
    string Author; // �����  �����

public:
    Book(string n, string Au);
    ~Book();
    string getAuthor(); //���������� ������ �����
    string getTitle();  //���������� �������� �����
};


//����� BookList//
//����� BookList � ������ ���� ����.
//�� �������� ��������� ���������� �� ����� Book
// � ��������� ��� ��� ������
class BookList
{
private:
    // ���������� ��������� �� �����
    list <Book*> setPtrsBook;  // ��������� �� ����� ����
    list <Book*>::iterator iter; //��������

public:
    ~BookList();            // ���������� (�������� ����)
    void insertBook(Book*); // �������� ����� � ������
    string getTitle(string);// ���������� ��������
    void display();         // ����� ������ ����
};

//����� BookInputScreen//
//����� BookInputScreen. ��� �����, ���������� �� ����������� �������,
//���� ������������ ����� ������ ������ � ����� �����:
class BookInputScreen
{
private:
    BookList* ptrBookList;
    string tTitle;
    string tAuthor;

public:
    BookInputScreen(BookList* ptrTL) : ptrBookList(ptrTL)
    {

    }
    void setBook(); // �������� ������ � �����
};

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

//�����  SellInputScreen //
//����� ��� ���������� �������
class SellInputScreen
{
private:
    BookList* ptrBookList;          // ������ ����
    SellRecord* ptrSellRecord;      // ������ ������� �� ������
    string SoldBook;                // �������� ��������� �����
    float SellPaid;                 // ������
    int month;                      // �� �����
public:
    SellInputScreen(BookList* ptrTL, SellRecord* ptrRR) : ptrBookList(ptrTL), ptrSellRecord(ptrRR)
    {

    }
    void setSell();  // �������� ����� ������ ���������� �� �����
};

//����� Expense//
//����� ������
class Expense
{
public:
    int month, day;  // ����� � ���� ������ ��������
    string category; // ��������� �������� (�����, ����, ������ � ��)
    string payee;    // ���� ������ (���������� ����, �����, ������)
    float amount;    // ������� ������
    Expense()
    {  }
    Expense(int m, int d, string c, string p, float a) :
        month(m), day(d), category(c), payee(p), amount(a)
    {

    }
};


//����� ExpenseRecord//
//����� ������� � ��������
class ExpenseRecord
{
private:
    vector<Expense*> vectPtrsExpenses; //������ ���������� �� �������
    vector<Expense*>::iterator iter;

public:
    ~ExpenseRecord();
    void insertExp(Expense*);
    void display();
    float displaySummary();  // ����� ��� �������� ������
};

//����� ExpenseInputScreen//
//����� ��� ����� ��������
class ExpenseInputScreen
{
private:
    ExpenseRecord* ptrExpenseRecord;  // ������ � ��������

public:
    ExpenseInputScreen(ExpenseRecord*);
    void setExpense();
};


//����� AnnualReport//
//����� �������� ������
class AnnualReport
{
private:
    SellRecord* ptrRR;     // ������ �������
    ExpenseRecord* ptrER;  // ������ ��������
    float expenses, Sells; // ����� ������� � ��������

public:
    AnnualReport(SellRecord*, ExpenseRecord*);
    void display();  // ����������� �������� ������
};



//����� UserInterface//
//������� ����� ��� ������� ����������:
//���� ����� ���������� �������������� ����� � ����������.
class UserInterface
{
private:
    BookList*            ptrBookList;
    BookInputScreen*     ptrBookInputScreen;
    SellRecord*          ptrSellRecord;
    SellInputScreen*     ptrSellInputScreen;
    ExpenseRecord*       ptrExpenseRecord;
    ExpenseInputScreen*  ptrExpenseInputScreen;
    AnnualReport*        ptrAnnualReport;
    char ch;

public:
    UserInterface();
    ~UserInterface();
    void interact();
};
