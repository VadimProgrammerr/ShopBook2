#ifndef BOOKINPUTSCREEN
#define BOOKINPUTSCREEN
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric>  //��� accumulate()
#include "booklist.h"
using namespace std;
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
#endif // BOOKINPUTSCREEN

