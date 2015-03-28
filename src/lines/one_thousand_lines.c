/* one_thousand_lines.c by Alan K Stewart */

#include "line_segments.h"

int lines = 1000;

Point get_point1(int n)
{
    Point p;
    p.x = sin(4 * PI * n / lines) * scale;
    p.y = cos(2 * PI * n / lines) * scale;
    return p;
}

Point get_point2(int n)
{
    Point p;
    p.x = 0.5 * sin(8 * PI * n / lines) * scale;
    p.y = 0.5 * cos(4 * PI * n / lines) * scale;
    return p;
}

LineSegment get_line(int n)
{
    LineSegment line;
    line.p1 = get_point1(n);
    line.p2 = get_point2(n);
    return line;
}
