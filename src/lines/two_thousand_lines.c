/* two_thousand_lines.c by Alan K Stewart */

#include "line_segments.h"

int lines = 2000;

point get_point(int l, int m, int n)
{
    point p;
    p.x = pow(sin(l * PI * n / lines), 3) * scale;
    p.y = pow(cos(m * PI * n / lines), 3) * scale;
    return p;
}

line_segment get_line(int n)
{
    line_segment line;
    line.p1 = get_point(12, 10, n);
    line.p2 = get_point(8, 6, n);
    return line;
}
