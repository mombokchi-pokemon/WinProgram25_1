#include <GLFW/glfw3.h>
#include <math.h>
#pragma comment(lib, "Opengl32.lib")
#define PI 3.1415926535f

typedef struct {
    float x, y;
} Vec2;

typedef struct {
    Vec2 position;
    float rotation;
    Vec2 scale;
} Transform;

typedef struct {
    Transform transform;
    int segments;
} Circle;

typedef struct {
    Transform transform;
} Triangle;

typedef struct {
    Vec2 start;
    Vec2 end;
    Transform transform;
} Line;

// 원 그리기
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

// 삼각형 그리기
void draw_triangle(Triangle* tri)
{
    glPushMatrix();
    glTranslatef(tri->transform.position.x, tri->transform.position.y, 0.0f);
    glRotatef(tri->transform.rotation * (180.0f / PI), 0.0f, 0.0f, 1.0f);
    glScalef(tri->transform.scale.x, tri->transform.scale.y, 1.0f);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glEnd();
    glPopMatrix();
}

// 선 그리기 (Transform 적용)
void draw_line(Line* line)
{
    glPushMatrix();
    glTranslatef(line->transform.position.x, line->transform.position.y, 0.0f);
    glRotatef(line->transform.rotation * (180.0f / PI), 0.0f, 0.0f, 1.0f);
    glScalef(line->transform.scale.x, line->transform.scale.y, 1.0f);

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2f(line->start.x, line->start.y);
    glVertex2f(line->end.x, line->end.y);
    glEnd();
    glPopMatrix();
}

int main()
{
    if (!glfwInit())
        return -1;

    GLFWwindow* window = glfwCreateWindow(800, 600, "Bonobono Rotating Triangle & Line", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glOrtho(-1, 1, -1, 1, -1, 1); // 2D

    // 원 객체들 (예시: 얼굴 등)
    Circle cir1 = { {{0,0}, 0, {400 / 800.0f * 2, 380 / 600.0f * 2}}, 100 };
    Circle cir2 = { {{-100 / 800.0f * 2, 0}, 0, {150 / 800.0f * 2, 140 / 600.0f * 2}}, 100 };
    // 삼각형 (tri1 회전용)
    Triangle tri1 = { {{160.0f / 800.0f * 2, -50.0f / 600.0f * 2}, 0, {40 / 800.0f * 2, 30 / 600.0f * 2}} };
    Triangle tri2 = { {{100 / 800.0f * 2, 50 / 600.0f * 2}, 0, {40 / 800.0f * 2, 30 / 600.0f * 2}} };

    // 선 두 개 (원점 기준 회전)
    Line line1 = {
        {0.0f, 0.0f},
        {200.0f / 800.0f * 2, -60.0f / 600.0f * 2},
        {{0.0f, 0.0f}, 0.0f, {1.0f, 1.0f}}
    };

    Line line2 = {
        {0.0f, 0.0f},
        {100.0f / 800.0f * 2, 60.0f / 600.0f * 2},
        {{0.0f, 0.0f}, 0.0f, {1.0f, 1.0f}}
    };

    Line line3 = {
        {-100 / 800.0f * 2, 0},
        {-170.0f / 800.0f * 2,0},
        {{0.0f, 0.0f}, 0.0f, {1.0f, 1.0f}}
    };


    // 메인 루프
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // 회전 애니메이션 (시계 방향)
        float time = (float)glfwGetTime();

        // tri1 회전 (원점 기준으로)
        float x0 = 175.0f / 800.0f * 2;
        float y0 = -50.0f / 600.0f * 2;
		float angle = -time * (2 * PI / 43200); // 12시간에 360도 회전
        tri1.transform.position.x = x0 * cosf(angle) - y0 * sinf(angle);
        tri1.transform.position.y = x0 * sinf(angle) + y0 * cosf(angle);
        tri1.transform.rotation = angle;

        // tri2 회전 (원점 기준으로)
        float x1 = 100 / 800.0f * 2;
        float y1 = 50 / 600.0f * 2;
        float angle1 = -time * (2 * PI / 3600);
        tri2.transform.position.x = x1 * cosf(angle1) - y1 * sinf(angle1);
        tri2.transform.position.y = x1 * sinf(angle1) + y1 * cosf(angle1);
        tri2.transform.rotation = angle1;

        // line1 회전 (분침, 60초에 360도 회전)
        line1.transform.rotation = -time * (2 * PI / 43200);

        // line2 회전 (시침, 12시간에 360도 회전)
        line2.transform.rotation = -time * (2 * PI / 3600);
        Vec2 pivot = { -100.0f / 800.0f * 2, 0.0f };
        float l3_angle = -time * (2 * PI / 60); // 원하는 회전 속도 (예: 초당 1 radian)

        Vec2 p1 = { -100.0f / 800.0f * 2, 0.0f };      // 원래 start 점
        Vec2 p2 = { -170.0f / 800.0f * 2, 0.0f };      // 원래 end 점

        // 회전 적용
        line3.start.x = cosf(l3_angle) * (p1.x - pivot.x) - sinf(l3_angle) * (p1.y - pivot.y) + pivot.x;
        line3.start.y = sinf(l3_angle) * (p1.x - pivot.x) + cosf(l3_angle) * (p1.y - pivot.y) + pivot.y;

        line3.end.x = cosf(l3_angle) * (p2.x - pivot.x) - sinf(l3_angle) * (p2.y - pivot.y) + pivot.x;
        line3.end.y = sinf(l3_angle) * (p2.x - pivot.x) + cosf(l3_angle) * (p2.y - pivot.y) + pivot.y;

        // 선 그리기
        draw_line(&line3);


        // 파란 원
        glColor3f(1.0f, 1.0f, 1.0f);
        draw_circle(&cir1);
        glColor3f(0.5f, 0.5f, 0.f);
        draw_circle(&cir2);

        // 선과 삼각형 회전
        glColor3f(0.0f, 0.0f, 0.0f);
        draw_line(&line1);
        draw_line(&line2);
        draw_line(&line3);
        draw_triangle(&tri1);
        draw_triangle(&tri2);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}