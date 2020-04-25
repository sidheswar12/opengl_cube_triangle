
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>

double rX=0;
double rY=0;

void drawCube()
{
        double x = 0.6;
        double y = 0.6;
        double z = 0.6;
        glClearColor(0.4, 0.4, 0.4, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        glRotatef( rX, 1.0, 0.0, 0.0 );
        glRotatef( rY, 0.0, 1.0, 0.0 );
        glBegin(GL_TRIANGLES);
        glColor3f(0.4, 0.3, 0.5);
        glVertex3f(x, y, z);
        glVertex3f(x, -y, z);
        glVertex3f(-x, y, z);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.5, 0.3, 0.2);
        glVertex3f(-x, -y, z);
        glVertex3f(x, -y, z);
        glVertex3f(-x, y, z);
        glEnd();
        glBegin(GL_TRIANGLES);
        glColor3f(0.1, 0.5, 0.3);
        glVertex3f(-x, y, -z);
        glVertex3f(0, 0, -z);
        glVertex3f(-x, -y, -z);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.0, 0.5, 0.0);
        glVertex3f(-x, -y, -z);
        glVertex3f(0, 0, -z);
        glVertex3f(x, -y, -z);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.1, 0.3, 0.3);
        glVertex3f(-x, y, -z);
        glVertex3f(x, y, -z);
        glVertex3f(0, 0, -z);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.2, 0.2, 0.2);
        glVertex3f(0, 0, -z);
        glVertex3f(x, y, -z);
        glVertex3f(x, -y, -z);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.3, 0.5, 0.6);
        glVertex3f(-x, -y, -z);
        glVertex3f(-x, -y, z);
        glVertex3f(-x, y, -z);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.5, 0.5, 0.5);
        glVertex3f(-x, y, z);
        glVertex3f(-x, -y, z);
        glVertex3f(-x, y, -z);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.2, 0.2, 0.2);
        glVertex3f(x, y, z);
        glVertex3f(x, y, -z);
        glVertex3f(x, -y, z);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(x, -y, -z);
        glVertex3f(x, y, -z);
        glVertex3f(x, -y, z);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.6, 0.0, 0.0);
        glVertex3f(x, y, z);
        glVertex3f(x, y, -z);
        glVertex3f(-x, y, -z);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.6, 0.1, 0.2);
        glVertex3f(-x, y, z);
        glVertex3f(x, y, z);
        glVertex3f(-x, y, -z);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.4, 0.0, 0.4);
        glVertex3f(-x, -y, -z);
        glVertex3f(-x, -y, z);
        glVertex3f(x, -y, z);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.3, 0.0, 0.3);
        glVertex3f(x, -y, -z);
        glVertex3f(-x, -y, -z);
        glVertex3f(x, -y, z);
        glEnd();

        glFlush();
        glutSwapBuffers();
}

void keyboard(int key, int x, int y)
{
        if (key == GLUT_KEY_RIGHT)
        {
                rY += 15;
        }
        else if (key == GLUT_KEY_LEFT)
        {
                rY -= 15;
        }
        else if (key == GLUT_KEY_DOWN)
        {
                rX -= 15;
        }
        else if (key == GLUT_KEY_UP)
        {
                rX += 15;
        }

        glutPostRedisplay();
}
