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

typedef struct Point {
    GLdouble x;
    GLdouble y;
} Point;

typedef struct LineSegment {
    Point p1;
    Point p2;
} LineSegment;

void init();
void display();
LineSegment get_line(int n);

#endif
