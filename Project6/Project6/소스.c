
#include <stdio.h>
#include <windows.h>
#include <string.h>

typedef struct {
    int x, y;
    int w, h;
    char* title;
    char* msg;
} Box;

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void drawBox(Box b) {
    gotoxy(b.x, b.y); printf("|");
    for (int i = 0; i < b.w; i++) printf("-");
    printf("|");

    gotoxy(b.x, b.y + 1); printf("|");
    int pad = (b.w - strlen(b.title)) / 2;
    for (int i = 0; i < pad; i++) printf(" ");
    printf("%s", b.title);
    for (int i = 0; i < b.w - pad - strlen(b.title); i++) printf(" ");
    printf("|");

    gotoxy(b.x, b.y + 2); printf("|");
    for (int i = 0; i < b.w; i++) printf("-");
    printf("|");

    for (int i = 0; i < b.h; i++) {
        gotoxy(b.x, b.y + 3 + i);
        printf("|");
        for (int j = 0; j < b.w; j++) printf(" ");
        printf("|");
    }

    gotoxy(b.x, b.y + 3 + b.h); printf("|");
    for (int i = 0; i < b.w; i++) printf("-");
    printf("|");
}

void fill_console_background(int color_code) {
    printf("\033[%dm", color_code);
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 200; j++) printf(" ");
        printf("\n");
    }
    printf("\033[0m");
}

int main() {
    system("cls");
    fill_console_background(42);

    Box box1 = { 10, 3, 30, 10, "박스1", "왼쪽 박스" };
    Box box2 = { 50, 3, 30, 10, "박스2", "오른쪽 박스" };

    drawBox(box1);
    drawBox(box2);

    // 캐릭터 위치
    int ox = box1.x + box1.w / 2;
    int oy = box1.y + 3 + box1.h / 2;

    Box* currentBox = &box1;

    while (1) {
        gotoxy(ox, oy); printf("O");
        Sleep(50);
        gotoxy(ox, oy); printf(" ");

        // 키 입력 처리
        if (GetAsyncKeyState('W') & 0x8000 && oy > currentBox->y + 3) oy--;
        if (GetAsyncKeyState('S') & 0x8000 && oy < currentBox->y + 2 + currentBox->h) oy++;
        if (GetAsyncKeyState('A') & 0x8000) {
            if (ox > currentBox->x + 1) {
                ox--;
            }
            else if (currentBox == &box2) {
                // box2 → box1 이동
                currentBox = &box1;
                ox = currentBox->x + currentBox->w;
            }
        }
        if (GetAsyncKeyState('D') & 0x8000) {
            if (ox < currentBox->x + currentBox->w) {
                ox++;
            }
            else if (currentBox == &box1) {
                // box1 → box2 이동
                currentBox = &box2;
                ox = currentBox->x + 1;
            }
        }

        if (GetAsyncKeyState('Q') & 0x8000) break;
    }

    gotoxy(0, box2.y + box2.h + 5);
    printf("게임 종료\n");
    return 0;
}