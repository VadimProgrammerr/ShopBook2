#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric>  //для accumulate()
using namespace std;

// глобальные методы //
void getaLine(string& inStr);  // получение строки текста
char getaChar();  // получение символа

// класс Book (Книги) //
//Он хранит Название и Автора книги, которые у нас есть.
class Book
{
private:
    string Title;  // Название
    string Author; // Автор  книги

public:
    Book(string n, string Au);
    ~Book();
    string getAuthor(); //возвращает Автора книги
    string getTitle();  //возвращает Название книги
};


//класс BookList//
//класс BookList — список всех Книг.
//Он содержит множество указателей на класс Book
// и оперирует ими при выводе
class BookList
{
private:
    // установить указатели на книги
    list <Book*> setPtrsBook;  // указатели на класс книг
    list <Book*>::iterator iter; //итератор

public:
    ~BookList();            // деструктор (удаление книг)
    void insertBook(Book*); // добавить книгу в список
    string getTitle(string);// возвращает Название
    void display();         // вывод списка книг
};

//класс BookInputScreen//
//класс BookInputScreen. Это класс, отвечающий за отображение «экрана»,
//куда пользователь может ввести данные о новой книги:
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
    void setBook(); // добавить данные о книге
};

//класс SellRow//
//класс, хранящий одну табличную строку доходов (купленных книг)
// одна строка таблицы прибыли: название и 12 месячных оплат
class SellRow
{
private:
    string tTitle;        // книга, за которые уплачено
    float Sell[12];       // месяцы

public:
    SellRow(string);                 // конструктор с одним параметром
    void setSell(int, float);        // добавить доход за месяц
    float getSumOfRow();             //сумма платежей из одной строки (доход с книги за все месяцы)
    string gettTitle();              //Запрос названия
    float getSellNo(int);            //Запрос дохода за месяц int
};


// класс SellRecord //
//класс SellRecord. Он хранит непосредственно записи об продаже.
//С ним будет взаимодействовать экран добавления дохода.
class SellRecord
{
private:
    list <SellRow*> setPtrsSR; // указатели на объекты SellRow (по одному на книгу)
    list <SellRow*>::iterator iter;
 public:
    ~SellRecord();
    void insertSell(string, int, float);    // добавить доход
    void display();                         // отобразить все строки с доходами
    float getSumOfSells();                  // подсчитать сумму доходов от всех книг
};

//класс  SellInputScreen //
//Экран для добавления продажи
class SellInputScreen
{
private:
    BookList* ptrBookList;          // список книг
    SellRecord* ptrSellRecord;      // список записей об оплате
    string SoldBook;                // название проданной книги
    float SellPaid;                 // оплата
    int month;                      // за месяц
public:
    SellInputScreen(BookList* ptrTL, SellRecord* ptrRR) : ptrBookList(ptrTL), ptrSellRecord(ptrRR)
    {

    }
    void setSell();  // добавить плату одного покупателя за месяц
};

//класс Expense//
//Класс затрат
class Expense
{
public:
    int month, day;  // месяц и день уплаты расходов
    string category; // категория расходов (книги, свет, ремонт и тд)
    string payee;    // кому платим (поставщики книг, света, аренда)
    float amount;    // сколько платим
    Expense()
    {  }
    Expense(int m, int d, string c, string p, float a) :
        month(m), day(d), category(c), payee(p), amount(a)
    {

    }
};


//класс ExpenseRecord//
//Класс записей о затратах
class ExpenseRecord
{
private:
    vector<Expense*> vectPtrsExpenses; //вектор указателей на расходы
    vector<Expense*>::iterator iter;

public:
    ~ExpenseRecord();
    void insertExp(Expense*);
    void display();
    float displaySummary();  // нужно для годового отчета
};

//класс ExpenseInputScreen//
//Класс для ввода расходов
class ExpenseInputScreen
{
private:
    ExpenseRecord* ptrExpenseRecord;  // запись о расходах

public:
    ExpenseInputScreen(ExpenseRecord*);
    void setExpense();
};


//класс AnnualReport//
//Класс годового отчета
class AnnualReport
{
private:
    SellRecord* ptrRR;     // записи доходов
    ExpenseRecord* ptrER;  // записи расходов
    float expenses, Sells; // суммы доходов и расходов

public:
    AnnualReport(SellRecord*, ExpenseRecord*);
    void display();  // отображение годового отчета
};



//Класс UserInterface//
//Главный класс для запуска приложения:
//этот класс определяет взаимодействие юзера с программой.
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
