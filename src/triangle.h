
#include "GL/freeglut.h"
#include "GL/gl.h"

void drawTriangle()
{
    glClearColor(255, 255, 255, 255);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0, 0, 0);
    
    glBegin(GL_TRIANGLES);
            glVertex3f(-1, -1, 0);
            glVertex3f(300, 400, 0);
            glVertex3f(0, 1, 0);
    glEnd();

    glFlush();
}