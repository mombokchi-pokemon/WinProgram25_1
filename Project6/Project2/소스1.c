#include <windows.h>
#include <stdio.h>

int main()
{
    while (1)
    {
        // W Ű�� ���ȴ��� Ȯ�� (key down)
        if (GetAsyncKeyState(0x41) & 0x8000)
        {
            printf("A Ű ���� (Key Down)\n");
        }

        //// S Ű�� ���ȴ��� Ȯ�� (key down)
        //if (GetAsyncKeyState(VK_S) & 0x8000) 
        //{
        //    printf("S Ű ���� (Key Down)\n");
        //}

        //// W Ű�� ���������� Ȯ�� (key up)
        //if (!(GetAsyncKeyState(VK_W) & 0x8000)) 
        //{
        //    printf("W Ű ������ (Key Up)\n");
        //}

        //// S Ű�� ���������� Ȯ�� (key up)
        //if (!(GetAsyncKeyState(VK_S) & 0x8000)) 
        //{
        //    printf("S Ű ������ (Key Up)\n");
        //}

        //// ���α׷� ���� ����
        //if (GetAsyncKeyState(VK_Q) & 0x8000) 
        //{
        //    printf("���� ����\n");
        //    break;  // Q Ű�� ������ ����
        //}
        //// ��� ��� (CPU ��� ����ȭ)
        //Sleep(10);
    }
    return 0;
}