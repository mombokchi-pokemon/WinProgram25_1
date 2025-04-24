#include <stdio.h>
#include <windows.h>

static void GotoXY(int x, int y) {
    COORD Pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void DrawBox(int x, int y, int width, int height) {
    // ��� ������
    GotoXY(x, y);
    for (int i = 0; i < width; i++) printf("-");

    // ������ �� ���� ����
    for (int i = 1; i < height - 1; i++) {
        GotoXY(x, y + i);
        printf("|");  // ���� �׵θ�
        for (int j = 1; j < width - 1; j++) printf(" ");  // ���� ����
        printf("|");  // ������ �׵θ�
    }

    // �ϴ� ������
    GotoXY(x, y + height - 1);
    for (int i = 0; i < width; i++) printf("-");
}

int main() {
    system("cls");  // ȭ�� �����
    system("color A0");  // �ܼ� ȭ���� ��� ������� ����

    DrawBox(5, 2, 20, 7);  // 20��7 ũ���� �ڽ�
    GotoXY(30, 30); // Ŀ���� �� �Ʒ��� �̵��Ͽ� ����ϰ� ����
    return 0;
}


/*����� ���ڿ�
<stdio.h>   <string.h>
char getch()���� �ϳ� �޾ƿ��°�

int puts(char[] string) ���ڿ� �޾ƿ��°� 

**************************************
*          �̼����� ����ϱ�        *
*****************************************

1.���ӽ���
2.���� 

�Է�>

  int choice;
            printf("%c\n", choice);

            if (choice == '1') {
                puts("\n���� ����");
            }
            else if (choice == '2'); {
                puts("\n���α׷����� �����մϴ�");
            }




            printf("���α׷� ����\n");
            return 0;



�̺�Ʈ �������� while�� ��� ����
-�������� ���� ó��
-���α׷� ������� ��� ����

"system("cls");




------------------0�w 
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

����ü�� ���� ,.




�Է°��� �޾Ƽ� �� ��� ��������? 













1.����ȭ�� �� ���� �ö� ������â�� �ּ� 3~4�� ����
2.�ߺ��Ǽ� �ٸ���ġ�� ��� �� �־���� 

3.�˾� ������ ������ �־���� (x,y) 
4.Ÿ��Ʋȭ�� ������ �⺻â �⺻��ġ�� ���ִ�
5. �ڷᱸ���� �������� .



1. ����ȭ�鿡 �ش��ϴ� ������ ������� ����ä���
�ܼ�â�� ���� ä�� ��(���� ����) ���� �������
 ȭ�鿡 �°Բ�
Ŀ�ǵ� ������Ʈ���� 

2. ����ȭ�� ���� ���� ���� �����츦 20*7 ũ��� 
10.3�뿡 �� �� 

3. �������� <�⺻ũ��/�⺻��ġ/�̸�/����>
�Ӽ��� struct ���·� �����غ��ÿ� (����ü ������?)
(�̰� �� ����� �𸣰��� �Ѿ��..)
�������� �̸��� ���� �̸��� �������.

4. �ٸ� �������� 15,5,�� ������ �����츦 ����غ��ÿ�

5. GIT�� ���ε��ϰ� Commit code ����





@echo off
color 2A
mode 1000
title ��� ����ȭ��
cls





#include <stdio.h>
#include <stdlib.h>
int main() {
    system("color A0");  // CMD ȭ���� ��� ������� ����
    return 0;

}

typedef struct COORD
{
    int x;
    int y;
};






*/