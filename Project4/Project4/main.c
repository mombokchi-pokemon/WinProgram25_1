#include <stdio.h>
#include <conio.h>

int main() {
    int pos = 5;  // 0�� �ʱ� ��ġ

    while (1) {
        system("cls");  // clear screen�� ���� 

        // ȭ�� ���
        for (int i = 0; i < 10; i++) {
            if (i == pos)
                putchar('0');  // pos ��ġ�� '0' ���
            else
                putchar('_');  // ���������� '��' ���
        }       // i�� 0���� 9���� ���µ� pos�� i�� ������ 0�� ��� �ƴϸ� -�� ���
        
        // Ű �Է�
        char key = _getch();
        if (key == 'a' && pos > 0) pos--;  // ����
        if (key == 'd' && pos < 9) pos++;  // ������
        if (key == 'q') break;  // ����
    }

    return 0;
}