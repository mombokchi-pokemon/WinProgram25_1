#include <stdio.h>
#include <conio.h>
#include "Display.h"

int main() {
    showMenu();

    char input;
    input = _getch();

    if (input == '1')
    {
        puts("GPT �̿���!");
    }
    else if (input == '2')
    {
        puts("���� ��ǥ�� ������ּ���!");
    }
    else
    {
        puts("���� �߸�������.");
    }

    return 0;
}