/* line_segments.h by Alan K Stewart */

#ifndef SRC_LINE_SEGMENTS_H_
#define SRC_LINE_SEGMENTS_H_

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>

#define SIZE 1024

static const double PI = 3.14159265358979323846264338327950288L;

extern int lines;
extern double scale;

typedef struct {
    GLdouble x;
    GLdouble y;
} point;

typedef struct {
    point p1;
    point p2;
} line_segment;

void init_2d();
void display();
line_segment get_line(int n);

#endif
