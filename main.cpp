#include "userinterface.h"
#include <clocale>

int main()
{
    //������� setlocale() ����� ����������� ���������.
    setlocale(LC_ALL, "rus");

    UserInterface theUserInterface;

    theUserInterface.interact();
    return 0;
}
