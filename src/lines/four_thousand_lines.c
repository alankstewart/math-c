/* four_thousand_lines.c by Alan K Stewart */

#include "line_segments.h"

int lines = 4000;

Point get_point(int l, int m, int n)
{
    Point p;
    p.x = sin(l * PI * n / lines) * scale;
    p.y = cos(m * PI * n / lines) * scale;
    return p;
}

LineSegment get_line(int n)
{
    LineSegment line;
    line.p1 = get_point(14, 22, n);
    line.p2 = get_point(26, 34, n);
    return line;
}
