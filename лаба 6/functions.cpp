#include "functions.h"
 
void wait()
{
    char a;
    std::cout << "��� ����������� ������� ����� �������...";
    a = _getch();
}
int input_int()
{
    int num;
    while (true)
    {
        std::cin >> num;
        if (std::cin.good())
            break;
        std::cin.clear();
        std::cout << "����������� ����" << std::endl;
        std::cin.ignore();
    }
    return num;
}