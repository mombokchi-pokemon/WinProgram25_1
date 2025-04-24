#include <stdio.h>
#include <windows.h>

static void GotoXY(int x, int y) {
    COORD Pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void DrawBox(int x, int y, int width, int height) {
    // 상단 가로줄
    GotoXY(x, y);
    for (int i = 0; i < width; i++) printf("-");

    // 세로줄 및 내부 공백
    for (int i = 1; i < height - 1; i++) {
        GotoXY(x, y + i);
        printf("|");  // 왼쪽 테두리
        for (int j = 1; j < width - 1; j++) printf(" ");  // 내부 공백
        printf("|");  // 오른쪽 테두리
    }

    // 하단 가로줄
    GotoXY(x, y + height - 1);
    for (int i = 0; i < width; i++) printf("-");
}

int main() {
    system("cls");  // 화면 지우기
    system("color A0");  // 콘솔 화면을 녹색 배경으로 변경

    DrawBox(5, 2, 20, 7);  // 20×7 크기의 박스
    GotoXY(30, 30); // 커서를 맨 아래로 이동하여 깔끔하게 정리
    return 0;
}


/*입출력 문자열
<stdio.h>   <string.h>
char getch()문자 하나 받아오는거

int puts(char[] string) 문자열 받아오는거 

**************************************
*          이성재의 비밀일기        *
*****************************************

1.게임시작
2.종료 

입력>

  int choice;
            printf("%c\n", choice);

            if (choice == '1') {
                puts("\n게임 시작");
            }
            else if (choice == '2'); {
                puts("\n프로그래밍을 종료합니다");
            }




            printf("프로그램 종료\n");
            return 0;



이벤트 루프에서 while문 사용 이유
-지속적인 대기와 처리
-프로그램 종료까지 계속 실행

"system("cls");




------------------0햣 
git \
git commit 
git push








-----------------------------------------
|                                              |
-----------------------------------------
|                                               |
|                                               |
|                                               |
|                                               |
-----------------------------------------

구조체는 설명서 ,.




입력값을 받아서 좌 우로 움직여라? 













1.바탕화면 그 위에 올라갈 윈도우창을 최소 3~4개 띄우기
2.중복되서 다른위치에 띄울 수 있어야함 

3.팝업 윈도우 같은게 있어야함 (x,y) 
4.타이틀화면 윈도우 기본창 기본위치가 들어가있는
5. 자료구조를 만들어야함 .



1. 바탕화면에 해당하는 영영을 녹색으로 가득채우기
콘솔창을 가득 채울 것(공백 없이) 배경색 노란색을
 화면에 맞게끔
커맨드 프롬포트에서 

2. 바탕화면 위에 어제 만든 윈도우를 20*7 크기로 
10.3쯤에 찍어볼 것 

3. 윈도우의 <기본크기/기본위치/이름/색상>
속성을 struct 형태로 관리해보시오 (구조체 관리법?)
(이거 안 배워서 모르겠음 넘어가자..)
윈도우의 이름을 본인 이름을 출력하자.

4. 다른 색상으로 15,5,에 동일한 윈도우를 출력해보시오

5. GIT에 업로드하고 Commit code 제출





@echo off
color 2A
mode 1000
title 녹색 바탕화면
cls





#include <stdio.h>
#include <stdlib.h>
int main() {
    system("color A0");  // CMD 화면을 녹색 배경으로 변경
    return 0;

}

typedef struct COORD
{
    int x;
    int y;
};






*/