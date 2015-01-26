/*
 This program uses a 3-D structure in OpenGL called a Nurb.  A nurb
 is a continuous surface that is controlled by a few distinct points.
 In this example, a three dimensional grid of 16 points is assigned
 some simple 3-D positions in space, but then several points are then
 skewed.  The first stretch moved the middle four points up to a height
 of 6, and then several of the corner points are moved as well.  The
 result is a curved surface that contains all of those points.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

GLfloat mat_color_diffuse[] = { 0.2, 0.6, 1.0, 1.0 };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess[] = { 100.0 };
GLfloat knots[8] = { 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0 };

GLfloat nurbarray[4][4][3];

GLUnurbsObj *nurb;

int row, col;
static double spin = 330.0;

static void display(void)
{
    glClearColor(0.3, 0.3, 0.3, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glCallList(1);
    glFlush();
}

void init()
{
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);
    nurb = gluNewNurbsRenderer();
    gluNurbsProperty(nurb, GLU_SAMPLING_TOLERANCE, 25.0);
    gluNurbsProperty(nurb, GLU_DISPLAY_MODE, GLU_FILL);
}

void create_surface()
{
    /* Build control points for NURBS surface */
    for (row = 0; row < 4; row++) {
        for (col = 0; col < 4; col++) {
            /* Initialize Nurb Array with a "bump" in the middle */
            nurbarray[row][col][0] = 2.0 * ((GLfloat) row);
            nurbarray[row][col][1] = 2.0 * ((GLfloat) col);
            nurbarray[row][col][2] = 0.0;

            /* Stretch up middle */
            if ((row == 1 || row == 2) && (col == 1 || col == 2)) {
                nurbarray[row][col][2] = 6.0;
            }
        }
    }

    /* Stretch far right corner in z direction */
    nurbarray[3][3][2] = 5.0;

    /* Stretch near corner in x direction */
    nurbarray[0][0][0] = -3.0;

    /* Stretch far right corner in y direction */
    nurbarray[3][0][1] = -2.0;
}

void create_view()
{
    glMatrixMode(GL_PROJECTION);
    gluPerspective(55.0, 1.0, 2.0, 24.0);
    glMatrixMode(GL_MODELVIEW);
    glTranslatef(-2.0, -1.0, -15.0);
    glRotatef(spin, 1.0, 0.0, 0.0);
}

void render_surface()
{
    glNewList(1, GL_COMPILE);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_color_diffuse);
    gluBeginSurface(nurb);
    gluNurbsSurface(nurb, 8, knots, 8, knots, 4 * 3, 3, &nurbarray[0][0][0], 4, 4, GL_MAP2_VERTEX_3);
    gluEndSurface(nurb);
    glEndList();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1024, 1024);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Nurb");
    init();
    create_surface();
    create_view();
    render_surface();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
