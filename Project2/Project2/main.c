#include <stdio.h>
#include <conio.h>  // getch() ����� ���� ���

void moveCharacter() {
    char input;
    int position = 0;  // ���� ��ġ �ʱ�ȭ






    while (1) {
        // ȭ�� �ʱ�ȭ
       system("cls");
 
        // ���� ���� ��ġ�� ���� ���
        for (int i = 0; i < position; i++) {
            printf(" ");  // ������ ���� ������ ��ġ �̵�
        }
        printf("0\n");  // 'A' ���ڸ� ���

        input = _getch();  // ����� �Է� �ޱ�

        if (input == 'a') {
            position--;  // 'a'�� ������ �ڷ� ���� (��ġ ����)
        }
        else if (input == 'd') {
            position++;  // 'd'�� ������ ������ ���� (��ġ ����)
        }
    }
}

int main() {
    printf("���ڸ� �ڷ� ���� �Ϸ��� 'a'��, ������ ���� �Ϸ��� 'd'�� ��������.\n");
    printf("���α׷� �����Ϸ��� 'q'�� ��������.\n");
    moveCharacter();  // ���� �̵� �Լ� ȣ��
    return 0;
}