/* solar.h by Alan K Stewart */

#ifndef SRC_SOLAR_H_
#define SRC_SOLAR_H_

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void init();
void reshape(int width, int height);
void display();

#endif
