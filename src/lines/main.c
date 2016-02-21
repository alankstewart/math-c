/* main.c by Alan K Stewart */

#include "line_segments.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int size = argc > 1 ? atoi(argv[1]) : SIZE;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(size, size);
    glutInitWindowPosition(100, 0);
    glutCreateWindow("Line Art");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return EXIT_SUCCESS;
}
