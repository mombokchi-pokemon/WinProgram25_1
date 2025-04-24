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
        system("cls");       // 화면 초기화
        gotoxy(x, y);
        printf("뭘봐");         // 캐릭터 출력

        // 키가 눌린 상태면 위치 이동
        if (GetAsyncKeyState('W') & 0x8000) y--;
        if (GetAsyncKeyState('S') & 0x8000) y++;
        if (GetAsyncKeyState('A') & 0x8000) x--;
        if (GetAsyncKeyState('D') & 0x8000) x++;

        // Q 누르면 종료
        if (GetAsyncKeyState('Q') & 0x8000) {
            printf("\n게임 종료\n");
            break;
        }

        Sleep(10); // 
    }

    return 0;
}

//배경 내가 원하는 부분만 검은색 칠하고 나머지는 파란색 칠하기 이런거 시험에 나올수도 있음