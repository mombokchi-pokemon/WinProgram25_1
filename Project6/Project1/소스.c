#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main() {
    int x = 10, y = 10;
    system("color 2F");
    while (1) {
        system("cls");       // ȭ�� �ʱ�ȭ
        gotoxy(x, y);
        printf("����");         // ĳ���� ���

        // Ű�� ���� ���¸� ��ġ �̵�
        if (GetAsyncKeyState('W') & 0x8000) y--;
        if (GetAsyncKeyState('S') & 0x8000) y++;
        if (GetAsyncKeyState('A') & 0x8000) x--;
        if (GetAsyncKeyState('D') & 0x8000) x++;

        // Q ������ ����
        if (GetAsyncKeyState('Q') & 0x8000) {
            printf("\n���� ����\n");
            break;
        }

        Sleep(10); // 
    }

    return 0;
}

//��� ���� ���ϴ� �κи� ������ ĥ�ϰ� �������� �Ķ��� ĥ�ϱ� �̷��� ���迡 ���ü��� ����