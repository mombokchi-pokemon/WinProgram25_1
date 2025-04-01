#include <stdio.h>
#include <conio.h>  // getch() 사용을 위한 헤더

void moveCharacter() {
    char input;
    int position = 0;  // 문자 위치 초기화






    while (1) {
        // 화면 초기화
       system("cls");
 
        // 현재 문자 위치에 문자 출력
        for (int i = 0; i < position; i++) {
            printf(" ");  // 공백을 통해 문자의 위치 이동
        }
        printf("0\n");  // 'A' 문자를 출력

        input = _getch();  // 사용자 입력 받기

        if (input == 'a') {
            position--;  // 'a'를 누르면 뒤로 가기 (위치 감소)
        }
        else if (input == 'd') {
            position++;  // 'd'를 누르면 앞으로 가기 (위치 증가)
        }
    }
}

int main() {
    printf("문자를 뒤로 가게 하려면 'a'를, 앞으로 가게 하려면 'd'를 누르세요.\n");
    printf("프로그램 종료하려면 'q'를 누르세요.\n");
    moveCharacter();  // 문자 이동 함수 호출
    return 0;
}