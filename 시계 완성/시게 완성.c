#include <GLFW/glfw3.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>  // bool, true, false 사용 가능하게 함
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
    Vec2 start;
    Vec2 end;
    Transform transform;
} Line;

void draw_circle(Circle* c)
{
    glPushMatrix();
    glTranslatef(c->transform.position.x, c->transform.position.y, 0.0f);
    glRotatef(c->transform.rotation * (180.0f / PI), 0.0f, 0.0f, 1.0f);
    glScalef(c->transform.scale.x, c->transform.scale.y, 1.0f);

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f);
    for (int i = 0; i <= c->segments; ++i) {
        float angle = 2.0f * PI * i / c->segments;
        glVertex2f(cosf(angle) * 0.5f, sinf(angle) * 0.5f);
    }
    glEnd();
    glPopMatrix();
}

void draw_line(Line* line)
{
    glPushMatrix();
    glTranslatef(line->transform.position.x, line->transform.position.y, 0.0f);
    glRotatef(line->transform.rotation * (180.0f / PI), 0.0f, 0.0f, 1.0f);
    glScalef(line->transform.scale.x, line->transform.scale.y, 1.0f);

    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(line->start.x, line->start.y);
    glVertex2f(line->end.x, line->end.y);
    glEnd();
    glPopMatrix();
}

const bool segments[10][7] = {
    {true,  true,  true,  true,  true,  true,  false}, // 0
    {false, true,  true,  false, false, false, false}, // 1
    {true,  true,  false, true,  true,  false, true }, // 2
    {true,  true,  true,  true,  false, false, true }, // 3
    {false, true,  true,  false, false, true,  true }, // 4
    {true,  false, true,  true,  false, true,  true }, // 5
    {true,  false, true,  true,  true,  true,  true }, // 6
    {true,  true,  true,  false, false, false, false}, // 7
    {true,  true,  true,  true,  true,  true,  true }, // 8
    {true,  true,  true,  true,  false, true,  true }  // 9
};

// 직선을 그리는 함수 (세그먼트를 그릴 때 사용)
void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

// 숫자 1자리를 구성하는 세그먼트 중 하나를 그림
void drawSegment(float x, float y, float size, int segmentIndex, bool on) {
    if (!on) return; // 해당 세그먼트가 꺼져 있으면 그림 생략

    float w = size;         // 세그먼트 길이 (가로/세로 기준)
    float h = size / 5.0f;  // 세그먼트 두께

    // 세그먼트 a~g를 각각 좌표 기준으로 그리기
    switch (segmentIndex) {
    case 0: drawLine(x, y, x + w, y); break;                   // a: 상단 수평선
    case 1: drawLine(x + w, y, x + w, y - w); break;           // b: 오른쪽 위 수직선
    case 2: drawLine(x + w, y - w, x + w, y - 2 * w); break;   // c: 오른쪽 아래 수직선
    case 3: drawLine(x, y - 2 * w, x + w, y - 2 * w); break;   // d: 하단 수평선
    case 4: drawLine(x, y - w, x, y - 2 * w); break;           // e: 왼쪽 아래 수직선
    case 5: drawLine(x, y, x, y - w); break;                   // f: 왼쪽 위 수직선
    case 6: drawLine(x, y - w, x + w, y - w); break;           // g: 중앙 수평선
    }
}

// 숫자 1자리를 그리는 함수 (7개의 세그먼트 구성)
void drawDigit(float x, float y, float size, int num) {
    for (int i = 0; i < 7; ++i) {
        drawSegment(x, y, size, i, segments[num][i]);
    }
}

// 전체 시계를 그리는 함수 (시, 분, 초 각 2자리씩)
void drawClock() {
    // 현재 시스템 시간 받아오기
    time_t now = time(NULL);
    struct tm* t = localtime(&now);

    int hour = t->tm_hour;
    int minute = t->tm_min;
    int second = t->tm_sec;

    // 👇 여기서부터 위치 및 크기 조절 가능
    float x = -0.33f;   // 시작 x 좌표 (왼쪽 끝 기준)
    float y = -0.21f;    // 숫자가 그려질 시작 y 좌표 (상단 기준)
    float size = 0.05f; // 숫자 크기 (세그먼트 길이)
    float spacing = 0.1f; // 숫자 사이의 간격

    // 시(hour)
    drawDigit(x, y, size, hour / 10); x += spacing;
    drawDigit(x, y, size, hour % 10); x += spacing;

    // 시-분 사이 콜론 (: 대신 점 2개 찍기)
    glBegin(GL_POINTS);
    glVertex2f(x + 0.05f, y - 0.5f * size);
    glVertex2f(x + 0.05f, y - 1.5f * size);
    glEnd();
    x += 0.05f; // 콜론 위치 보정 후 다음 숫자 위치로 이동

    // 분(minute)
    drawDigit(x, y, size, minute / 10); x += spacing;
    drawDigit(x, y, size, minute % 10); x += spacing;

    // 분-초 사이 콜론
    glBegin(GL_POINTS);
    glVertex2f(x + 0.05f, y - 0.5f * size);
    glVertex2f(x + 0.05f, y - 1.5f * size);
    glEnd();
    x += 0.05f;

    // 초(second)
    drawDigit(x, y, size, second / 10); x += spacing;
    drawDigit(x, y, size, second % 10);
}
void draw_ticks(float radius, int count) {
    glBegin(GL_LINES);
    for (int i = 0; i < count; ++i) {
        float angle = 2 * PI * i / count;
        float outer_x = cosf(angle) * radius;
        float outer_y = sinf(angle) * radius;
        float inner_x = cosf(angle) * (radius - 0.03f);
        float inner_y = sinf(angle) * (radius - 0.03f);
        glVertex2f(inner_x, inner_y);
        glVertex2f(outer_x, outer_y);
    }
    glEnd();
}


int main()
{
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(1600, 1600, "Analog Clock with Subdial", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glOrtho(-1, 1, -1, 1, -1, 1);

    glClearColor(0.95f, 0.95f, 1.0f, 1.0f);

    // 본체 및 중심
    Circle clock_face = { {{0, 0}, 0, {400.0f / 800.0f * 2, 400.0f / 800.0f * 2}}, 100 };
    Circle center_dot = { {{0, 0}, 0, {6.0f / 800.0f * 2, 6.0f / 600.0f * 2}}, 20 };

    // 시/분 침
    Line hour_hand = {
        {0, 0}, {0.0f, 100.0f / 600.0f * 2},
        {{0, 0}, 0, {0.02f, 1.0f}}
    };
    Line minute_hand = {
        {0, 0}, {0.0f, 150.0f / 600.0f * 2},
        {{0, 0}, 0, {0.015f, 1.0f}}
    };

    // 초침 위치를 왼쪽으로 이동한 작은 원 안에서 회전
    Vec2 subdial_pos = { -0.3f, 0.0f }; // 왼쪽 위에 위치한 보조 다이얼

    Circle subdial = { {subdial_pos, 0, {100.0f / 800.0f * 2, 100.0f / 600.0f * 2}}, 50 };
    Circle subdial_center_dot = { {subdial_pos, 0, {4.0f / 800.0f * 2, 4.0f / 600.0f * 2}}, 20 };

    Line second_hand = {
        {0, 0}, {0.0f, 50.0f / 600.0f * 2},
        {subdial_pos, 0, {0.008f, 1.0f}}
    };



    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        float time = (float)glfwGetTime();

        float sec_angle = -time * (2 * PI / 60);
        float min_angle = -time * (2 * PI / 3600);
        float hour_angle = -time * (2 * PI / 43200);

        // 회전 적용
        hour_hand.transform.rotation = hour_angle;
        minute_hand.transform.rotation = min_angle;
        second_hand.transform.rotation = sec_angle;

        // 초침 끝 원 위치 계산
       
        // 본체 시계
        glColor3f(0.85f, 0.85f, 0.85f); draw_circle(&clock_face);
        glColor3f(0.1f, 0.1f, 0.1f); draw_line(&hour_hand);
        glColor3f(0.0f, 0.0f, 0.0f); draw_line(&minute_hand);
        glColor3f(0.0f, 0.0f, 0.0f); draw_circle(&center_dot);

        // 서브 다이얼 초침
        glColor3f(0.9f, 0.9f, 0.9f); draw_circle(&subdial);
        glColor3f(1.0f, 0.0f, 0.0f); draw_line(&second_hand);
        glColor3f(1.0f, 0.0f, 0.0f); 
        glColor3f(0.0f, 0.0f, 0.0f); draw_circle(&subdial_center_dot);

        glColor3f(0.0f, 1.0f, 0.0f); // 숫자 색상: 초록
        glColor3f(0.0f, 0.0f, 0.0f);
        drawClock(); // 시계 그리기
        
		draw_ticks(400/800.0f, 12); // 시계 바깥쪽 눈금

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
