/*#include <GLFW/glfw3.h>
#include <math.h>
#pragma comment(lib, "Opengl32.lib")
#define PI 3.1415926535f

typedef struct { float x, y; } Vec2;
typedef struct { Vec2 position; float rotation; Vec2 scale; } Transform;

typedef struct {
    Transform transform;
    int segments;
} Circle;

typedef struct {
    Vec2 start;
    Vec2 end;
    Transform transform;
    float r, g, b;
    float width;
} Line;

// 원 그리기
void draw_circle(Circle* c, float r, float g, float b)
{
    glPushMatrix();
    glTranslatef(c->transform.position.x, c->transform.position.y, 0.0f);
    glRotatef(c->transform.rotation * (180.0f / PI), 0.0f, 0.0f, 1.0f);
    glScalef(c->transform.scale.x, c->transform.scale.y, 1.0f);

    glColor3f(r, g, b);
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

// 선 그리기
void draw_line(Line* line)
{
    glPushMatrix();
    glTranslatef(line->transform.position.x, line->transform.position.y, 0.0f);
    glRotatef(line->transform.rotation * (180.0f / PI), 0.0f, 0.0f, 1.0f);
    glScalef(line->transform.scale.x, line->transform.scale.y, 1.0f);

    glColor3f(line->r, line->g, line->b);
    glLineWidth(line->width);
    glBegin(GL_LINES);
    glVertex2f(line->start.x, line->start.y);
    glVertex2f(line->end.x, line->end.y);
    glEnd();
    glPopMatrix();
}

// 눈금 점 그리기
void draw_ticks(int count)
{
    for (int i = 0; i < count; ++i)
    {
        float angle = 2.0f * PI * i / count;
        float outer = 0.9f;
        float inner = (i % 5 == 0) ? 0.8f : 0.85f; // 큰 눈금/작은 눈금

        float x1 = cosf(angle) * inner;
        float y1 = sinf(angle) * inner;
        float x2 = cosf(angle) * outer;
        float y2 = sinf(angle) * outer;

        glLineWidth((i % 5 == 0) ? 3.0f : 1.0f);
        glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glEnd();
    }
}

int main()
{
    if (!glfwInit())
        return -1;

    GLFWwindow* window = glfwCreateWindow(800, 800, "Elegant Clock", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glOrtho(-1, 1, -1, 1, -1, 1); // 2D

    Circle clockFace = { {{0, 0}, 0, {0.9f, 0.9f}}, 100 };
    Circle centerDot = { {{0, 0}, 0, {0.02f, 0.02f}}, 30 };

    Line hourHand = {
        {0.0f, 0.0f}, {0.0f, 0.4f}, {{0, 0}, 0, {1, 1}},
        0.0f, 0.0f, 0.0f, 6.0f
    };
    Line minuteHand = {
        {0.0f, 0.0f}, {0.0f, 0.6f}, {{0, 0}, 0, {1, 1}},
        0.2f, 0.2f, 0.2f, 4.0f
    };
    Line secondHand = {
        {0.0f, 0.0f}, {0.0f, 0.75f}, {{0, 0}, 0, {1, 1}},
        1.0f, 0.0f, 0.0f, 2.0f
    };

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.95f, 0.95f, 0.95f, 1.0f); // 밝은 배경
        glClear(GL_COLOR_BUFFER_BIT);

        float t = (float)glfwGetTime();

        // 시침/분침/초침 회전 계산
        secondHand.transform.rotation = -t * (2 * PI / 60);
        minuteHand.transform.rotation = -t * (2 * PI / 3600);
        hourHand.transform.rotation = -t * (2 * PI / 43200);

        // 시계 배경
        draw_circle(&clockFace, 0.9f, 0.9f, 1.0f); // 밝은 파랑
        glColor3f(0.0f, 0.0f, 0.0f);
        draw_ticks(60); // 눈금
        draw_circle(&centerDot, 0.0f, 0.0f, 0.0f); // 중심점

        // 바늘들
        draw_line(&hourHand);
        draw_line(&minuteHand);
        draw_line(&secondHand);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
*/