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
    cout << "Введите Название: " << endl;
    cin >> tTitle;
    cout << "Введите Автора: " << endl;
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
    cout << "\nНазвание\tАвтор\n-------------------\n";
    if (setPtrsBook.empty()) // если список книг пуст
  cout << "***Нет авторов***\n" << endl; // выводим запись, что он пуст)
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
    cout << "\nНазвание   Янв  Фев  Мар  Апр  Май  Июн Июл  Авг  Сен  Окт  Ноя  Дек Сумма,руб\n" << endl
        << "-------------------------------------------------------------------------------\n" << endl;
    if (setPtrsSR.empty())  	 	cout << "***Нет доходов!***\n" << endl;
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
    cout << "Название: ";
    cin >> SoldBook;
    cout << "Введите сумму платежа: " << endl;
    cin >> SellPaid;       // вводим оплату
    cin.ignore(80, '\n');
    cout << "Введите номер месяца оплаты (1-12): " << endl;
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
    cout << "\nДата\tПолучатель\tСумма\tКатегория\n"
        << "----------------------------------------\n" << endl;
    if (vectPtrsExpenses.size() == 0) // В контейнере нет расходов
        cout << "***Расходов нет***\n" << endl;
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
        cout << "\tВсе категории\t0\n";
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
            case '1': ptrBookList->display();
                break;
            case '2': ptrSellRecord->display();
                break;
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
