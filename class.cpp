#include <iostream>
#include "class.h"

void getaLine(string& inStr) // получение строки текста
{
    char temp[21];
    cin.get(temp, 20, '\n');
    cin.ignore(20, '\n');     //число пропускаемых символов и символ разделения
    inStr = temp;
}
//---------------------------------------------------------

char getaChar()                     // получение символа
{
    char ch = cin.get();
    cin.ignore(80, '\n');   //число пропускаемых символов и символ разделения
    return ch;
}
//---------------------------------------------------------

//методы класса Book//
//в конструкторе задаём Название и Автора
Book::Book(string n, string Au) : Title(n), Author(Au)
{

}
//---------------------------------------------------------

Book::~Book() // деструктор
{

}
//---------------------------------------------------------

string Book::getAuthor() //геттер возвращает Название
{
    return Author;
}
//--------------------------------------------------------

string Book::getTitle() //геттер возвращает Автора
{
    return Title;
}
//---------------------------------------------------------

//метод класса BookInputScreen//
void BookInputScreen::setBook() // добавить данные о книге
{
    cout << "Title: " << endl;
    cin >> tTitle;
    cout << "Author: " << endl;
    cin >> tAuthor;
    cin.ignore(80, '\n');
    Book* ptrBook = new Book(tTitle, tAuthor);   // создать книгу
    ptrBookList->insertBook(ptrBook);            // занести в список книг

}
//---------------------------------------------------------

//методы класса BookList//
BookList::~BookList() // деструктор
{
    while (!setPtrsBook.empty()) // удаление всех книг,
 {          // удаление указателей из контейнера
        iter = setPtrsBook.begin();
        delete *iter;
        setPtrsBook.erase(iter);
    }
}
//---------------------------------------------------------


void BookList::insertBook(Book* ptrT)
{
    setPtrsBook.push_back(ptrT); // вставка новой книги
}
//---------------------------------------------------------


void BookList::display()     // вывод списка книг
{
    cout << "\nTitle\tAuthor\n-------------------\n";
    if (setPtrsBook.empty()) // если список книг пуст
  cout << "***List empty***\n" << endl; // выводим запись, что он пуст)
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

//методы класса SellRow//
SellRow::SellRow(string an) : tTitle(an) //конструктор
{
    //Алгоритм fill() помещает копию значения value (у нас это 0)
    //в каждый элемент диапазона, ограниченного парой итераторов [first,last).
    //Т.е. в конструкторе просто инициализируем массив значениями 0.
    fill(&Sell[0], &Sell[12], 0);
}
//---------------------------------------------------------

void SellRow::setSell(int m, float am) // сеттер оплата за месяц m, сумма - am
{
    Sell[m] = am;   // привязываем оплату к месяцу
}
//---------------------------------------------------------

string SellRow::gettTitle() // геттер запрос названия
{
    return tTitle;
}
//---------------------------------------------------------

float SellRow::getSellNo(int month) //Геттер запрос дохода за месяц month
{
    return Sell[month];
}
//---------------------------------------------------------

float SellRow::getSumOfRow() // cумма доходов в строке
{
    //По умолчанию алгоритм accumulate() суммирует элементы.
    //Нужно указать точку старта, конечную точку и значение от которого начинаем прибавлять.
    //Чаще всего это ноль, но может быть и результат других вычислений.
    return accumulate(&Sell[0], &Sell[12], 0);
}
//---------------------------------------------------------

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

//методы класса SellInputScreen//
void SellInputScreen::setSell()
{
    cout << "Title: ";
    cin >> SoldBook;
    cout << "Number of money: " << endl;
    cin >> SellPaid;       // вводим оплату
    cin.ignore(80, '\n');
    cout << "Enter month (1-12): " << endl;
    cin >> month;
    cin.ignore(80, '\n');
    month--;                  // (внутренняя нумерация 0-11)
    // вставляем доход в запись об оплате
    ptrSellRecord->insertSell(SoldBook, month, SellPaid);

}
//---------------------------------------------------------

//методы класса expenseRecord//
ExpenseRecord::~ExpenseRecord() // деструктор
{ 	// удалить объекты expense
    // удалить указатели на вектор
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

void ExpenseRecord::display() // распечатываем все расходы
{
    cout << "\nDate\tPoluchatel\tSumm\tCategory\n"
        << "----------------------------------------\n" << endl;
    if (vectPtrsExpenses.size() == 0) // В контейнере нет расходов
        cout << "***List empty***\n" << endl;
    else
    {
        iter = vectPtrsExpenses.begin();
        while (iter != vectPtrsExpenses.end())
        {     // распечатываем все расходы
               cout << (*iter)->month << '/' << (*iter)->day << '\t' << (*iter)->payee << '\t' << '\t';
               cout << (*iter)->amount << '\t' << (*iter)->category << endl;
               iter++;
        }
        cout << endl;
    }
}
//--------------------------------------------------------

// используется при составлении годового отчета
float ExpenseRecord::displaySummary()
{
    float totalExpenses = 0; // Сумма по всем категориям расходов

    if (vectPtrsExpenses.size() == 0)
    {
        cout << "\tAll category\t0\n";
        return 0;
    }

    iter = vectPtrsExpenses.begin();
    while (iter != vectPtrsExpenses.end())
    {
        //выводим на экран категории расходов
        cout << '\t' << ((*iter)->category) << '\t' << ((*iter)->amount) << endl;
        totalExpenses += (*iter)->amount;  //подсчитываем все расходы
        iter++;
    }

    return totalExpenses;
}
//--------------------------------------------------------

//методы класса ExpenseInputScreen//
// конструктор
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
    // создаем новый расход
    Expense* ptrExpense = new Expense(month, day, category, payee, amount);
    // вставляем расход в список всех расходов
    ptrExpenseRecord->insertExp(ptrExpense);
}
//---------------------------------------------------------

//методы класса AnnualReport//
//Конструктор
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
        cout << expenses << endl;  	 	// вычисляем прибыльность
        cout << "\nBalance: " << (Sells - expenses) << endl;
}
//---------------------------------------------------------


//методы класса userInterface//
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
        if (ch == '1') // ввод данных
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
            }                   // конец секции switch
        }                       // конец условия if
        else if (ch == '2')     // вывод данных
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
            }                 // конец switch
        }                     // конец elseif
        else if (ch == '3')
            return;           // выход
        else
            cout << "Error";
    }                         // конец while
}                             // конец interact()

