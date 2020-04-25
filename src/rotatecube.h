#include <iostream>
#include <stdlib.h>
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

float angle = 0.0;

void drawCube3D()
{
        double x = 0.6;
        double y = 0.6;
        double z = 0.6;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glTranslatef(0.0, 0.0, -5.0);
        GLfloat ambientColor[] = {0.2, 0.2, 0.2, 1.0};
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
        GLfloat lightColor0[] = {0.5, 0.5, 0.5, 1.0};
        GLfloat lightPos0[] = {4.0, 0.0, 8.0, 1.0};
        glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
        glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

        glTranslatef(0.5, 1.0, 0.0);
        glRotatef(angle, 1.0, 1.0, 1.0);

        glRotatef(angle, 1.0, 0.0, 1.0);
        glRotatef(angle, 0.0, 1.0, 1.0);
        glTranslatef(-0.5, -1.0, 0.0);

       
        glBegin(GL_POLYGON);
                glColor3f(0.5, 0.3, 0.2);
                glVertex3f(x, -y, z);
                glVertex3f(x, y, z);
                glVertex3f(-x, y, z);
                glVertex3f(-x, -y, z);
        glEnd();

        
        glBegin(GL_POLYGON);
                glColor3f(0.0, 0.5, 0.0);
                glVertex3f(-x, y, -z);
                glVertex3f(-x, -y, -z);
                glVertex3f(x, -y, -z);
                glVertex3f(x, y, -z);
        glEnd();

       
        glBegin(GL_POLYGON);
        glColor3f(0.5, 0.5, 0.5);
        glVertex3f(-x, -y, -z);
        glVertex3f(-x, -y, z);
        glVertex3f(-x, y, z);
        glVertex3f(-x, y, -z);
        glEnd();


        glBegin(GL_POLYGON);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(x, -y, -z);
        glVertex3f(x, -y, z);
        glVertex3f(x, y, z);
        glVertex3f(x, y, -z);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.6, 0.0, 0.0);
        glVertex3f(x, y, z);
        glVertex3f(-x, y, z);
        glVertex3f(-x, y, -z);
        glVertex3f(x, y, -z);
        glEnd();


        glBegin(GL_POLYGON);
        glColor3f(0.3, 0.0, 0.3);
        glVertex3f(-x, -y, -z);
        glVertex3f(-x, -y, z);
        glVertex3f(x, -y, z);
        glVertex3f(x, -y, -z);
        glEnd();

        glFlush();
        glutSwapBuffers();
}

void update(int value)
{
        angle += 1.0f;
        if (angle > 360)
        {
                angle -= 360;
        }

        glutPostRedisplay();
        glutTimerFunc(25, update, 0);
}

void initRendering()
{
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_COLOR_MATERIAL);

        glClearColor(0.7f, 0.8f, 1.0f, 1.0f);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_NORMALIZE);
}

void handleResize(int w, int h)
{
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}
