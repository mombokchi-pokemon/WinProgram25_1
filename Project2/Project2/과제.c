#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>

int main() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(500, 500, "GLFW: �ﰢ�� ���� ���� �� �����", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // �ﰢ�� ���� ���� ��ó�� �����
        glBegin(GL_TRIANGLES);
        // �ﰢ������ ���� ���� (12��)
        glColor3f(0.0f, 0.0f, 1.0f); // �Ķ��� (�ܻ�)
        glVertex2f(0.0f, 0.0f); glVertex2f(0.5f, 0.0f); glVertex2f(0.49f, 0.09f);
        glVertex2f(0.0f, 0.0f); glVertex2f(0.49f, 0.09f); glVertex2f(0.47f, 0.18f);
        glVertex2f(0.0f, 0.0f); glVertex2f(0.47f, 0.18f); glVertex2f(0.43f, 0.25f);
        glVertex2f(0.0f, 0.0f); glVertex2f(0.43f, 0.25f); glVertex2f(0.38f, 0.33f);
        glVertex2f(0.0f, 0.0f); glVertex2f(0.38f, 0.33f); glVertex2f(0.31f, 0.40f);
        glVertex2f(0.0f, 0.0f); glVertex2f(0.31f, 0.40f); glVertex2f(0.25f, 0.43f);
        glVertex2f(0.0f, 0.0f); glVertex2f(0.25f, 0.43f); glVertex2f(0.18f, 0.47f);
        glVertex2f(0.0f, 0.0f); glVertex2f(0.18f, 0.47f); glVertex2f(0.09f, 0.49f);
        glVertex2f(0.0f, 0.0f); glVertex2f(0.09f, 0.49f); glVertex2f(0.0f, 0.5f);
        glVertex2f(0.0f, 0.0f); glVertex2f(0.0f, 0.5f); glVertex2f(-0.09f, 0.49f);
        glVertex2f(0.0f, 0.0f); glVertex2f(-0.09f, 0.49f); glVertex2f(-0.18f, 0.47f);
        glVertex2f(0.0f, 0.0f); glVertex2f(-0.18f, 0.47f); glVertex2f(-0.25f, 0.43f);
        glVertex2f(0.0f, 0.0f); glVertex2f(-0.25f, 0.43f); glVertex2f(-0.31f, 0.40f);
        glVertex2f(0.0f, 0.0f); glVertex2f(-0.31f, 0.40f); glVertex2f(-0.38f, 0.33f);
        glVertex2f(0.0f, 0.0f); glVertex2f(-0.38f, 0.33f); glVertex2f(-0.43f, 0.25f);
        glVertex2f(0.0f, 0.0f); glVertex2f(-0.43f, 0.25f); glVertex2f(-0.47f, 0.18f);
        glVertex2f(0.0f, 0.0f); glVertex2f(-0.47f, 0.18f); glVertex2f(-0.49f, 0.09f);
        glVertex2f(0.0f, 0.0f); glVertex2f(-0.49f, 0.09f); glVertex2f(-0.5f, 0.0f);
        glVertex2f(0.0f, 0.0f); glVertex2f(-0.5f, 0.0f); glVertex2f(-0.49f, -0.09f);
        glVertex2f(0.0f, 0.0f); glVertex2f(-0.49f, -0.09f); glVertex2f(-0.47f, -0.18f);
        glVertex2f(0.0f, 0.0f); glVertex2f(-0.47f, -0.18f); glVertex2f(-0.43f, -0.25f);
        glVertex2f(0.0f, 0.0f); glVertex2f(-0.43f, -0.25f); glVertex2f(-0.38f, -0.33f);
        glVertex2f(0.0f, 0.0f); glVertex2f(-0.38f, -0.33f); glVertex2f(-0.31f, -0.40f);
        glVertex2f(0.0f, 0.0f); glVertex2f(0.0f, -0.5f); glVertex2f(0.09f, -0.49f);
        glVertex2f(0.0f, 0.0f); glVertex2f(0.09f, -0.49f); glVertex2f(0.18f, -0.47f);
        glVertex2f(0.0f, 0.0f); glVertex2f(0.18f, -0.47f); glVertex2f(0.25f, -0.43f);
        glVertex2f(0.0f, 0.0f); glVertex2f(0.25f, -0.43f); glVertex2f(0.31f, -0.40f);
        glVertex2f(0.0f, 0.0f); glVertex2f(0.31f, -0.40f); glVertex2f(0.38f, -0.33f);
        glVertex2f(0.0f, 0.0f); glVertex2f(0.38f, -0.33f); glVertex2f(0.43f, -0.25f);
        glVertex2f(0.0f, 0.0f); glVertex2f(0.43f, -0.25f); glVertex2f(0.47f, -0.18f);
        glVertex2f(0.0f, 0.0f); glVertex2f(0.47f, -0.18f); glVertex2f(0.49f, -0.09f);
        glVertex2f(0.0f, 0.0f); glVertex2f(0.49f, -0.09f); glVertex2f(0.5f, 0.0f);
        glVertex2f(0.0f, 0.0f); glVertex2f(-0.5f, 0.0f); glVertex2f(-0.49f, -0.09f);
        glVertex2f(0.0f, 0.0f); glVertex2f(-0.49f, -0.09f); glVertex2f(-0.47f, -0.18f);
        glVertex2f(0.0f, 0.0f); glVertex2f(-0.47f, -0.18f); glVertex2f(-0.43f, -0.25f);
        glVertex2f(0.0f, 0.0f); glVertex2f(-0.43f, -0.25f); glVertex2f(-0.38f, -0.33f);
        glVertex2f(0.0f, 0.0f); glVertex2f(-0.38f, -0.33f); glVertex2f(-0.31f, -0.40f);
        glVertex2f(0.0f, 0.0f); glVertex2f(-0.31f, -0.40f); glVertex2f(-0.25f, -0.43f);
        glVertex2f(0.0f, 0.0f); glVertex2f(-0.25f, -0.43f); glVertex2f(-0.18f, -0.47f);
        glVertex2f(0.0f, 0.0f); glVertex2f(-0.18f, -0.47f); glVertex2f(-0.09f, -0.49f);
        glVertex2f(0.0f, 0.0f); glVertex2f(-0.09f, -0.49f); glVertex2f(0.0f, -0.5f);
        glEnd();
        glBegin(GL_TRIANGLES);

        // ù ��° �ﰢ�� (���� �Ʒ� - ������ �Ʒ� - ������ ��)
        glColor3f(1.0f, 0.0f, 0.0f); // ������
        glVertex2f(0.5f, 0.2f);
        glVertex2f(0.9f, 0.2f);
        glVertex2f(0.9f, 0.6f);

        // �� ��° �ﰢ�� (���� �Ʒ� - ������ �� - ���� ��)
        glColor3f(0.0f, 1.0f, 0.0f); // �ʷϻ�
        glVertex2f(0.5f, 0.2f);
        glVertex2f(0.9f, 0.6f);
        glVertex2f(0.5f, 0.6f);

        glEnd();


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}