#include "class.h"

int main()
{
    //������� setlocale() ����� ����������� ���������.
    setlocale(LC_ALL, "rus");

    UserInterface theUserInterface;

    theUserInterface.interact();
    return 0;
}
