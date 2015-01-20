/* two_thousand_lines.c by Alan K Stewart */

#include "two_thousand_lines.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GLUT/glut.h>
#include <OpenGL/OpenGL.h>

#define SIZE  768
#define LINES 2000
#define PI    3.14159265358979323846

int main(int argc, char *argv[])
{
    int size = argc > 1 ? atoi(argv[1]) : SIZE;
    scale = size * 15 / 32;

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
    int width = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(width / -2, width / 2, height / -2, height / 2);
}

void display(void)
{
    int i;
    line line;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.2f, 0.2f, 0.2f);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);

    glBegin(GL_LINES);
    for (i = 1; i <= LINES; i++) {
        line = getLine(i);
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
