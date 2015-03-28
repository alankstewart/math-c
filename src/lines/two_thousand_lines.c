/* two_thousand_lines.c by Alan K Stewart */

#include "line_segments.h"

int lines = 2000;

Point get_point(int l, int m, int n)
{
    Point p;
    p.x = pow(sin(l * PI * n / lines), 3) * scale;
    p.y = pow(cos(m * PI * n / lines), 3) * scale;
    return p;
}

LineSegment get_line(int n)
{
    LineSegment line;
    line.p1 = get_point(12, 10, n);
    line.p2 = get_point(8, 6, n);
    return line;
}
