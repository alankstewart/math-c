/* two_thousand_lines.h by Alan K Stewart */

#ifndef SRC_TWO_THOUSAND_LINES_H_
#define SRC_TWO_THOUSAND_LINES_H_

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

double scale;

typedef struct {
    GLdouble x;
    GLdouble y;
} point;

typedef struct {
    point p1;
    point p2;
} line;

void init2D();
void display();
line getLine(int n);
point getPoint(int l, int m, int n);

#endif
