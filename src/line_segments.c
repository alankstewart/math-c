/* two_thousand_lines.c by Alan K Stewart */

#include "line_segments.h"
#include <stdio.h>
#include <stdlib.h>

double scale;

void init_2d()
{
    GLdouble right = glutGet(GLUT_WINDOW_WIDTH) * -0.5;
    GLdouble left = fabs(right);
    GLdouble top = glutGet(GLUT_WINDOW_HEIGHT) * -0.5;
    GLdouble bottom = fabs(top);
    scale = left;

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(left, right, bottom, top);
}

void display()
{
    int n;
    line_segment line;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH, GL_NICEST);

    glBegin(GL_LINES);
    for (n = 1; n <= lines; n++) {
        line = get_line(n);
        glColor3f(0.2f, 0.3f, 0.3f);
        glVertex2d(line.p1.x, line.p1.y);
        glColor3f(0.0f, 0.1f, 0.3f);
        glVertex2d(line.p2.x, line.p2.y);
    }
    glEnd();
    glFlush();
}
