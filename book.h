#ifndef BOOK
#define BOOK
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric>  //��� accumulate()
using namespace std;
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
#endif // BOOK

