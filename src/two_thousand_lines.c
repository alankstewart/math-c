/* two_thousand_lines.c by Alan K Stewart */

#include "two_thousand_lines.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LINES 2000
#define SIZE  1024
#define PI    3.14159265358979323846264338327950288

int main(int argc, char *argv[])
{
    int size = argc > 1 ? atoi(argv[1]) : SIZE;
    scale = size / 2.0;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(size, size);
    glutInitWindowPosition(100, 0);
    glutCreateWindow("Line Art");
    init2D();
    glutDisplayFunc(display);
    glutMainLoop();
    return EXIT_SUCCESS;
}

void init2D()
{
    GLdouble right = glutGet(GLUT_WINDOW_WIDTH) / -2.0;
    GLdouble left = fabs(right);
    GLdouble top = glutGet(GLUT_WINDOW_HEIGHT) / -2.0;
    GLdouble bottom = fabs(top);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(left, right, bottom, top);
}

void display(void)
{
    line line;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.2f, 0.2f, 0.2f);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH, GL_NICEST);

    glBegin(GL_LINES);
    for (int n = 1; n <= LINES; n++) {
        line = getLine(n);
        glVertex2d(line.p1.x, line.p1.y);
        glVertex2d(line.p2.x, line.p2.y);
    }
    glEnd();
    glFlush();
}

line getLine(int n)
{
    line line;
    line.p1 = getPoint(12, 10, n);
    line.p2 = getPoint(8, 6, n);
    return line;
}

point getPoint(int l, int m, int n)
{
    point p;
    p.x = pow(sin(l * PI * n / LINES), 3) * scale;
    p.y = pow(cos(m * PI * n / LINES), 3) * scale;
    return p;
}
