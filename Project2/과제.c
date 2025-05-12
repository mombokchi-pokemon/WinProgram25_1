#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>

int main() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(500, 500, "GLFW: 삼각형 여러 개로 원 만들기", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // 삼각형 여러 개로 원처럼 만들기
        glBegin(GL_TRIANGLES);
        // 삼각형으로 원을 형성 (12개)
        glColor3f(0.0f, 0.0f, 1.0f); // 파란색 (단색)
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

        // 첫 번째 삼각형 (왼쪽 아래 - 오른쪽 아래 - 오른쪽 위)
        glColor3f(1.0f, 0.0f, 0.0f); // 빨간색
        glVertex2f(0.5f, 0.2f);
        glVertex2f(0.9f, 0.2f);
        glVertex2f(0.9f, 0.6f);

        // 두 번째 삼각형 (왼쪽 아래 - 오른쪽 위 - 왼쪽 위)
        glColor3f(0.0f, 1.0f, 0.0f); // 초록색
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