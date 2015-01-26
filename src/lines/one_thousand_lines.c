/* one_thousand_lines.c by Alan K Stewart */

#include "line_segments.h"

int lines = 1000;

point get_point1(int n)
{
    point p;
    p.x = sin(4 * PI * n / lines) * scale;
    p.y = cos(2 * PI * n / lines) * scale;
    return p;
}

point get_point2(int n)
{
    point p;
    p.x = 0.5 * sin(8 * PI * n / lines) * scale;
    p.y = 0.5 * cos(4 * PI * n / lines) * scale;
    return p;
}

line_segment get_line(int n)
{
    line_segment line;
    line.p1 = get_point1(n);
    line.p2 = get_point2(n);
    return line;
}
