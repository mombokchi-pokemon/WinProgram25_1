#include <windows.h>
#include <stdio.h>

int main() {

    POINT mousePos;     // ���콺 ��ġ

    // �ܼ� ȭ�� �ʱ�ȭ
    system("cls");

    while (1) {
        // ���콺 ��ġ ���
        GetCursorPos(&mousePos);

        // ȭ�� ���� (�巡�� ���� ���� ��ġ ����)
        system("cls");  // ȭ�� �ʱ�ȭ
        printf("���� ���콺 ��ġ: (%d, %d)\n", mousePos.x / 9, mousePos.y / 19);



        // ���콺 ��ġ ǥ��
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD) { mousePos.x / 9, mousePos.y / 19 });
        printf("<");

        // ���� ����: Q Ű�� ������ ���α׷� ����
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            printf("\n���α׷� ����\n");
            break;
        }

        // ��� ��� (CPU ��� ����ȭ)
        Sleep(10);
    }

    return 0;
}