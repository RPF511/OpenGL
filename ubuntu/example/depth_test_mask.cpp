#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

GLfloat xAngle, yAngle;
GLboolean bDepthTest = GL_TRUE;
GLboolean bCullFace = GL_FALSE;
GLboolean iOutline = GL_FALSE;

void mydisplay(){
    //DEPTH BUFFER CLEAR
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_FALSE);

    glColor3f(0.62,0.45,0.35);
    glBegin(GL_POLYGON);
    glVertex3f(-0.9,-0.9,0.1);
    glVertex3f(0.9,-0.9,0.1);
    glVertex3f(0.9,0.9,0.1);
    glVertex3f(-0.9,0.9,0.1);
    glEnd();

    glColor3f(0.92,0.63,0.45);
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.5,-0.5,0.5);
    glVertex3f(0.5,-0.5,0.5);
    glVertex3f(0.5,0.5,0.5);
    glEnd();

    glDepthMask(GL_TRUE);
    glColorMask(GL_FALSE, GL_FALSE,GL_FALSE,GL_FALSE);

    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.9,-0.9,0.1);
    glVertex3f(0.9,-0.9,0.1);
    glVertex3f(0.9,0.9,0.1);
    glVertex3f(-0.9,0.9,0.1);
    glEnd();

    glColorMask(GL_TRUE,GL_TRUE,GL_TRUE,GL_TRUE);
    
    glFlush();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA|GLUT_DEPTH);
    glutCreateWindow("depth test");
    glutInitWindowSize(300,300);
    glutInitWindowPosition(500,100);
    
    glMatrixMode(GL_PROJECTION);

    glutDisplayFunc(mydisplay);
    glOrtho(-1,1,-1,1,1,-1);

    glutMainLoop();
    return 0;  
}