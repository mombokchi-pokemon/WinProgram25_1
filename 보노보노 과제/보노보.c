#include <GLFW/glfw3.h>
#include <math.h>
#pragma comment(lib, "Opengl32.lib")
#define PI 3.1415926535f

typedef struct
{
    float x, y;
} Vec2;

typedef struct
{
    Vec2 position;
    float rotation;
    Vec2 scale;
} Transform;

typedef struct
{
    Transform transform;
    int segments;
} Circle;

// 원 그리기 함수 (위치, 크기, 회전 적용)
void draw_circle(Circle* c)
{
    glPushMatrix();
    glTranslatef(c->transform.position.x, c->transform.position.y, 0.0f);
    glRotatef(c->transform.rotation * (180.0f / PI), 0.0f, 0.0f, 1.0f);
    glScalef(c->transform.scale.x, c->transform.scale.y, 1.0f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f);
    for (int i = 0; i <= c->segments; ++i)
    {
        float angle = 2.0f * PI * i / c->segments;
        glVertex2f(cosf(angle) * 0.5f, sinf(angle) * 0.5f);
    }
    glEnd();
    glPopMatrix();
}

void draw_line(float x1, float y1, float x2, float y2)
{
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

int main()
{
    if (!glfwInit())
        return -1;

    GLFWwindow* window = glfwCreateWindow(800, 600, "Bonobono Blue Circle with Outline", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glOrtho(-1, 1, -1, 1, -1, 1); // 2D

    // 검은색 테두리 (조금 크게)
    Circle cir2 = { {{0, 0}, 0, {405 / 800.0f * 2, 385 / 600.0f * 2}}, 100 }; // 약간 큰 검은색 원 (테두리)

    // 파란색 원 (정확한 크기)
    Circle cir1 = { {{0, 0}, 0, {400 / 800.0f * 2, 380 / 600.0f * 2}}, 100 }; // 정확한 파란색 원
    Circle nose = { {{0, -25 / 600.0f * 2}, 0, {60 / 800.0f * 2, 60 / 600.0f * 2}}, 100 }; // 정확한 파란색 원
    Circle nose1 = { {{40 / 800.0f * 2, -60 / 600.0f * 2}, 0, {90 / 800.0f * 2, 75 / 600.0f * 2}}, 100 }; // 수염
    Circle nose2 = { {{-40 / 800.0f * 2, -60 / 600.0f * 2}, 0, {90 / 800.0f * 2, 75 / 600.0f * 2}}, 100 }; // 수염
    Circle left_eye = {
        {{-170 / 800.0f * 2, 30 / 600.0f * 2}, 0, {30 / 800.0f * 2, 30 / 600.0f * 2}},
        100
    };

    // 오른쪽 눈 (중앙에서 오른쪽으로 100px)
    Circle right_eye = {
        {{170 / 800.0f * 2, 30/600.0f * 2}, 0, {30 / 800.0f * 2, 30 / 600.0f * 2} },
        100
    };


    // 메인 루프
    while (!glfwWindowShouldClose(window))
    {
        // 화면 초기화
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // 하얀색 배경

        // 검은색 테두리
        glColor3f(0.0f, 0.0f, 0.0f);
        draw_circle(&cir2);

        // 보노보노 파란색 원 (안쪽)
        glColor3f(0.0f, 0.4392f, 0.7490f);
        draw_circle(&cir1);
        
        glColor3f(0.0f, 0.0f, 0.0f);
        draw_circle(&left_eye);

        // 검은색 오른쪽 눈
        draw_circle(&right_eye);
        //짭수염
        glColor3f(1.0f, 1.0f, 1.0f);
        draw_circle(&nose1);
        draw_circle(&nose2);
        //코
        glColor3f(0.0f, 0.0f, 0.0f);
		draw_circle(&nose);
        //왼쪽 진짜 수염
        draw_line(45 / 800.0f * 2, -60 / 600.0f * 2, 115 / 800.0f * 2, -60 / 600.0f * 2);
        draw_line(45 / 800.0f * 2, -40 / 600.0f * 2, 115 / 800.0f * 2, -20 / 600.0f * 2);
        draw_line(45 / 800.0f * 2, -80 / 600.0f * 2, 115 / 800.0f * 2, -100 / 600.0f * 2);
        //오른쪽 진짜 수염 
		draw_line(-45 / 800.0f * 2, -60 / 600.0f * 2, -115 / 800.0f * 2, -60 / 600.0f * 2);
		draw_line(-45 / 800.0f * 2, -40 / 600.0f * 2, -115 / 800.0f * 2, -20 / 600.0f * 2);
		draw_line(-45 / 800.0f * 2, -80 / 600.0f * 2, -115 / 800.0f * 2, -100 / 600.0f * 2);


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}