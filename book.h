#ifndef BOOK
#define BOOK
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric>  //для accumulate()
using namespace std;
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
#endif // BOOK

