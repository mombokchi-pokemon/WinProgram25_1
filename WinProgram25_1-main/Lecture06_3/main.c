#include <windows.h>
#include <stdio.h>

int main() {
    while (1) {
        // ���� ���콺 ��ư ���ȴ��� Ȯ�� (key down)
        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
            printf("���� ���콺 ��ư ���� (Key Down)\n");
        }

        // ������ ���콺 ��ư ���ȴ��� Ȯ�� (key down)
        if (GetAsyncKeyState(VK_RBUTTON) & 0x8000) {
            printf("������ ���콺 ��ư ���� (Key Down)\n");
        }

        // ���� ���콺 ��ư ���������� Ȯ�� (key up)
        if (!(GetAsyncKeyState(VK_LBUTTON) & 0x8000)) {
            printf("���� ���콺 ��ư ������ (Key Up)\n");
        }

        // ������ ���콺 ��ư ���������� Ȯ�� (key up)
        if (!(GetAsyncKeyState(VK_RBUTTON) & 0x8000)) {
            printf("������ ���콺 ��ư ������ (Key Up)\n");
        }

        // ���콺�� X, Y ��ǥ ��������
        POINT p;
        GetCursorPos(&p);  // ���콺�� ���� ȭ�� ��ǥ�� p�� ����
        printf("���콺 ��ġ: X=%d, Y=%d\n", p.x, p.y);

        // ���α׷� ���� ����
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            printf("���� ����\n");
            break;  // Q Ű�� ������ ����
        }

        // ��� ��� (CPU ��� ����ȭ)
        Sleep(10);
    }

    return 0;
}