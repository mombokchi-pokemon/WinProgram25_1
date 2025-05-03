#include <stdio.h>
#include <windows.h>
#include <string.h>

typedef struct {
    int x, y;            // ��ġ
    int w, h;            // �ʺ�, ����
    char* title;         // ����
    char* msg;           // �޽���
} Box;

// Ŀ�� �̵� �Լ�
void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// �ڽ� ��� �Լ� (�𼭸��� |�� ǥ��)
void drawBox(Box b) {
    // ����
    gotoxy(b.x, b.y);
    printf("|");
    for (int i = 0; i < b.w; i++) printf("-");
    printf("|");

    // ������
    gotoxy(b.x, b.y + 1);
    printf("|");
    int pad = (b.w - strlen(b.title)) / 2;
    for (int i = 0; i < pad; i++) printf(" ");
    printf("%s", b.title);
    for (int i = 0; i < b.w - pad - strlen(b.title); i++) printf(" ");
    printf("|");

    // ���м�
    gotoxy(b.x, b.y + 2);
    printf("|");
    for (int i = 0; i < b.w; i++) printf("-");
    printf("|");

    // ���� ����
    for (int i = 0; i < b.h; i++) {
        gotoxy(b.x, b.y + 3 + i);
        printf("|");
        if (i == b.h / 2) {
            int msg_pad = (b.w - strlen(b.msg)) / 2;
            for (int j = 0; j < msg_pad; j++) printf(" ");
            printf("%s", b.msg);
            for (int j = 0; j < b.w - msg_pad - strlen(b.msg); j++) printf(" ");
        }
        else {
            for (int j = 0; j < b.w; j++) printf(" ");
        }
        printf("|");
    }

    // �Ʒ���
    gotoxy(b.x, b.y + 3 + b.h);
    printf("|");
    for (int i = 0; i < b.w; i++) printf("-");
    printf("|");
}

void fill_console_background(int color_code) {
    printf("\033[%dm", color_code); // ANSI ���� ����

    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 200; j++) {
            printf(" ");
        }
        printf("\n");
    }

    printf("\033[0m"); // �� �ʱ�ȭ
}

int main() {
    system("cls");  // ȭ�� �����

    fill_console_background(42);

    printf("\033[41m");
    Box box1 = { 10, 3, 20, 7, "�ȳ��Ͻʴϱ�", "������" };
    drawBox(box1);

    gotoxy(0, 20);
    printf("\033[43m");
    Box box2 = { 15, 5, 20, 7, "�������", "������" };
    drawBox(box2);

    gotoxy(0, 20);
    printf("\033[0m"); // �� �ʱ�ȭ
    return 0;
}