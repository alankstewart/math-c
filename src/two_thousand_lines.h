/* two_thousand_lines.h by Alan K Stewart */

#ifndef SRC_TWO_THOUSAND_LINES_H_
#define SRC_TWO_THOUSAND_LINES_H_

double scale;

typedef struct {
    double x;
    double y;
} point;

typedef struct {
    point p1;
    point p2;
} line;

void init2D();
void display(void);
line getLine(int n);
point getPoint(int l, int m, int n);

#endif
