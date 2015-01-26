/*  Light1.c   This programs draws a simple Solar system that animates constantly */

#include <math.h>
#include <stdlib.h>
#include <GLUT/glut.h>

void init()
{
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };     // Define highlight properties
    GLfloat mat_shininess[] = { 50.0 };                  // Define shininess of surface
    GLfloat light_position[] = { 10.0, 40.0, 1.0, 0.0 }; // Define light source position

    glClearColor(0.3, 0.3, 0.3, 0.0);                    // Set background to gray
    glShadeModel(GL_SMOOTH);                             // Smooth transitions between edges
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);   // Set material properties
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess); // Set material properties
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);   // Set light properties
    glColorMaterial(GL_FRONT, GL_DIFFUSE);               // Set Color Capability

    glEnable(GL_COLOR_MATERIAL); // Enable color
    glEnable(GL_LIGHTING);       // Enable lighting for surfaces
    glEnable(GL_LIGHT0);         // Enable light source
    glEnable(GL_DEPTH_TEST);     // Enable depth buffering
}

void reshape(int width, int height)
{
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat) width / (GLfloat) height, 1.00, 30.0);
    gluLookAt(0.0, 2.5, 3.0, 0.0, -0.5, -1.0, 0.0, 1.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display()
{
    static double x; // This value will be remembered each time display is called

    x += 2; // Increment 2 degrees each call
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();                // Begin drawing image
    glRotatef(x, 0.0, 1.0, 0.0);   // Rotate
    glColor3f(1.0, 0.0, 0.0);      // Set Drawing Color to Red
    glutSolidSphere(0.70, 30, 20); // Draw Sphere(Radius, Slices, Stacks)
    glPushMatrix();                // Draw orbiting planet
    glTranslatef(1.1, 0.0, -1.0);  // Move away from origin
    glColor3f(1.0, 1.0, 0.0);      // Set color to yellow
    glutSolidSphere(0.3, 20, 16);  // Draw Sphere
    glPushMatrix();                // Draw Moon
    glRotatef(x, 0.0, 1.0, 0.0);   // Rotate
    glTranslatef(0.3, 0.0, -0.5);  // Move reference point
    glColor3f(0.0, 0.0, 1.0);      // Color Blue
    glutSolidSphere(0.12, 20, 16); // Draw Sphere
    glPopMatrix();                 // Return to former reference
    glPopMatrix();                 // Return to first reference
    glPushMatrix();                // Draw orbiting planet
    glTranslatef(-0.5, 0.0, 1.0);  // Move reference point
    glColor3f(0.0, 1.0, 0.0);      // Set color to green
    glutSolidSphere(0.2, 20, 16);  // Draw sphere
    glPopMatrix();                 // Return to first reference
    glPopMatrix();                 // Return to base reference
    glFlush();                     // Flush drawing routines
    glutSwapBuffers();             // Swap buffers
    glutPostRedisplay();           // Display results
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1024, 1024);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Light");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return EXIT_SUCCESS;
}
